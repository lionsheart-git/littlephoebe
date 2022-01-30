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
    def __filter_list(lis: list, regex: str) -> list:
        regex = re.compile(regex)
        return [i for i in lis if not regex.search(i)]

    @staticmethod
    def __filter_header(lis: list) -> list:
        pass

    @staticmethod
    def __root_dirs_files(path: str) -> (str, list, list):
        from os import walk

        f = []
        for (dirpath, dirnames, filenames) in walk(path):
            # Try to filter test and example directories
            dirnames = Library.__filter_list(dirnames, r'.*test*')
            dirnames = Library.__filter_list(dirnames, r'.*example*')

            return dirpath, dirnames, filenames

    @staticmethod
    def __create_library(root: str, dirs: list, files: list):
        print(f'Creating library in {root}')

    @staticmethod
    def index(path: str):

        path = path.strip(os.sep)

        root, dirs, files = Library.__root_dirs_files(path)
        subdirectories = list()

        if 'library.properties' in files:
            if 'CMakeLists.txt' not in files:
                Library.__create_library(root, dirs, files)
            return True
        else:
            for directory in dirs:
                if Library.index(f'{root}{os.sep}{directory}'):
                    subdirectories.append(directory)

        if subdirectories:
            print(f'{os.path.basename(root)} subdirectories:')
            for subd in subdirectories:
                print(subd)
            return True
        # import os
        # for root, dirs, files in os.walk(path):
        #     if 'library.properties' in files and 'CMakeLists.txt' not in files:
        #         lib_name = os.path.basename(root)
        #         sources = glob.glob('*.c[pp]')
        #         headers = glob.glob('*.h')
        #         for dir in dirs:
        #             print(f'add_subdirectory({dir})')
        #         print(
        #             f'generate_arduino_library({lib_name}\n'
        #             f'SRCS {Library.__list_to_string(sources)}\n'
        #             f'HDRS {Library.__list_to_string(headers)}\n)'
        #         )
        #         print(f'target_include_directories({lib_name} PUBLIC ${{CMAKE_CURRENT_SOURCE_DIR}})')
        # with open(f'{root}{os.sep}CMakeLists.txt', 'w') as file:
        # file.write(f'target_include_directories({lib_name} PUBLIC ${{CMAKE_CURRENT_SOURCE_DIR}})')
        # path = root.split(os.sep)
        # print((len(path) - 1) * '  ', os.path.basename(root), '/')
        # for file in files:
        #     print(len(path) * '  ', file)
