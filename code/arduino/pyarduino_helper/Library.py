import glob
import os
import re


class Library:

    @staticmethod
    def __walk_path(path: str):
        import os
        for root, dirs, files in os.walk(path):
            yield root, dirs, files

    @staticmethod
    def __list_to_string(lis: list) -> str:
        return ' '.join(str(elem) for elem in lis)

    @staticmethod
    def __filter_not_list(lis: list, regex: str) -> list:
        regex = re.compile(regex)
        return [i for i in lis if not regex.search(i)]

    @staticmethod
    def __filter_list(lis: list, regex: str) -> list:
        regex = re.compile(regex)
        return [i for i in lis if regex.search(i)]

    @staticmethod
    def __filter_header(lis: list) -> list:
        pass

    @staticmethod
    def __root_dirs_files(path: str) -> (str, list, list):
        from os import walk

        for (dirpath, dirnames, filenames) in walk(path):
            # Try to filter test, example and hidden directories
            dirnames = Library.__filter_not_list(dirnames, r'.*test.*')
            dirnames = Library.__filter_not_list(dirnames, r'.*example.*')
            dirnames = Library.__filter_not_list(dirnames, r'\..*')
            dirnames = Library.__filter_not_list(dirnames, r'.*extra.*')
            dirnames = Library.__filter_not_list(dirnames, r'.*build.*')
            dirnames = Library.__filter_not_list(dirnames, r'.*doc.*')

            return dirpath, dirnames, filenames

    @staticmethod
    def __collect_headers_sources(path: str):
        root, dirs, files = Library.__root_dirs_files(path)

        # Filter header and sources from files
        headers = Library.__filter_list(files, r"\.hp{,2}$")
        sources = Library.__filter_list(files, r"\.cp{,2}$")

        for directory in dirs:
            sub_headers, sub_sources = Library.__collect_headers_sources(f'{root}{os.sep}{directory}')

            for header in sub_headers:
                headers.append(f'{directory}{os.sep}{header}')

            for source in sub_sources:
                sources.append(f'{directory}{os.sep}{source}')

        if headers or sources:
            return headers, sources

    @staticmethod
    def __create_library(path: str):

        headers, sources = Library.__collect_headers_sources(path)

        print(f'Creating library in {path}')

        from pyarduino_helper.Cmake import CMakeLists
        library = CMakeLists(os.path.basename(path), path, 'w')
        library.generate_arduino_library(Library.__list_to_string(headers), Library.__list_to_string(sources))
        library.target_include_directory()

    @staticmethod
    def index(path: str):

        path = path.strip(os.sep)

        root, dirs, files = Library.__root_dirs_files(path)
        subdirectories = list()

        if 'library.properties' in files:
            if 'CMakeLists.txt' not in files:
                Library.__create_library(root)
            return True
        else:
            for directory in dirs:
                if Library.index(f'{root}{os.sep}{directory}'):
                    subdirectories.append(directory)

        if subdirectories:
            print(f'{os.path.basename(root)} subdirectories:')

            from pyarduino_helper.Cmake import CMakeLists
            library = CMakeLists(os.path.basename(path), path, 'w')
            library.add_subdirectories(subdirectories)

            return True
