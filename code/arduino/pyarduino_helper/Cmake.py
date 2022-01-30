import os


class CMakeLists:

    def __init__(self, lib_name: str, path: str, mode: str):
        self.__lib_name = f'{lib_name}_lib'
        self.__file = open(f'{path}{os.sep}CMakeLists.txt', mode)

    def generate_arduino_library(self, headers: str, sources: str, libs: str = None, board: str = None):
        string = f'generate_arduino_library({self.__lib_name}\n'
        if sources:
            string += f'\tSRCS {sources}\n'

        if headers:
            string += f'\tHDRS {headers}\n)'

        if libs:
            string += f'\tLIBS {libs}'

        if board:
            string += f'\tBOARD {board}'

        self.__file.write(f'{string}\n')

    def target_include_directory(self):
        self.__file.write(f'target_include_directories({self.__lib_name} PUBLIC ${{CMAKE_CURRENT_SOURCE_DIR}})\n')

    def add_subdirectory(self, subdirectory: str):
        self.__file.write(f'add_subdirectory({subdirectory})\n')

    def add_subdirectories(self, subdirectories: list):
        for subdir in subdirectories:
            self.add_subdirectory(subdir)

