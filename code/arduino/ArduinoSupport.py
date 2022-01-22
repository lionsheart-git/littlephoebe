#!/usr/bin/env python3

import subprocess


class Executor:

    @staticmethod
    def __get_file(path: str):
        from pathlib import Path
        return Path(path).stem + '.hex'

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
        sanitized_file = Executor.__get_file(file)
        print(sanitized_file)
        process = subprocess.Popen(
            ['avrdude', f'-c{programmer}', f'-p{partno}', f'-P{port}', f'-U{memtype}:{mode}:{sanitized_file}'],
            cwd='./build',
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


def __parse_args():
    import argparse

    parser = argparse.ArgumentParser(
        description='Utility for compiling and uploading files to arduino uno.',
        epilog='Hope that helps you with uploading files to the arduino.'
    )
    parser.add_argument(
        '--debug',
        action='store_true',
        help='Activate debug info.'
    )
    subparser = parser.add_subparsers(
        required=True
    )

    # Parser for compiling and uploading in one step
    sp = subparser.add_parser(
        'all',
        help='Compile and upload a file to the arduino.'
    )
    sp.set_defaults(cmd='all')
    sp.add_argument(
        'target',
        metavar='HEX',
        type=str,
        help='Name of the hex file to upload to the arduino uno.'
    )

    # Parser for compiling a sketch
    sp = subparser.add_parser(
        'compile',
        help='Compiles the cmake in the current directory.'
    )
    sp.set_defaults(cmd='compile')

    # Parser for uploading a hex to the arduino
    sp = subparser.add_parser(
        'upload',
        help='Upload a file to the arduino.'
    )
    sp.set_defaults(cmd='upload')
    sp.add_argument(
        'target',
        metavar='HEX',
        type=str,
        help='Upload a hex file to the arduino uno.'
    )

    return parser.parse_args()


def main():
    args = __parse_args()

    if args.cmd == 'compile' or args.cmd == 'all':
        print('Compile')
        Executor.compile()

    if args.cmd == 'upload' or args.cmd == 'all':
        print(f'Uploading {args.target}')
        Executor.upload(args.target)


if __name__ == '__main__':
    main()
