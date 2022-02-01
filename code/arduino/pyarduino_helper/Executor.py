import subprocess


class Executor:

    @staticmethod
    def __get_file(path: str):
        from pathlib import Path
        path_obj = Path(path)
        return path_obj.parent, path_obj.stem + '.hex'

    @staticmethod
    def upload(
            file: str,
            programmer: str = 'arduino',
            partno: str = 'ATMEGA328p',
            port: str = '/dev/ttyS3',
            memtype: str = 'flash',
            mode: str = 'w',
            baudrate: str = None,
            bitclock: str = None,
            config: str = None,
            delay: str = None,
            format: str = None,
            exitspec: str = None,
            extended_param: str = None,
            number: str = None,
            logfile: str = None
    ):
        path, sanitized_file = Executor.__get_file(file)
        print(path)
        print(sanitized_file)
        process = subprocess.Popen(
            ['avrdude', f'-c{programmer}', f'-p{partno}', f'-P{port}', f'-U{memtype}:{mode}:{sanitized_file}'],
            cwd=f'./{path}',
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE
        )
        stdout, stderr = process.communicate()
        print(stdout.decode())
        print(stderr.decode())

    @staticmethod
    def run_cmake():
        process = subprocess.Popen(['cmake', '..'],
                                   cwd='./build',
                                   stdout=subprocess.PIPE,
                                   stderr=subprocess.PIPE
                                   )
        stdout, stderr = process.communicate()
        print(stdout.decode())
        print(stderr.decode())

    @staticmethod
    def run_make():
        process = subprocess.Popen(['make'],
                                   cwd='./build',
                                   stdout=subprocess.PIPE,
                                   stderr=subprocess.PIPE
                                   )
        stdout, stderr = process.communicate()
        print(stdout.decode())
        print(stderr.decode())

    @staticmethod
    def compile():
        Executor.run_cmake()
        Executor.run_make()