#!/usr/bin/env python3

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

    # Parser for uploading a hex to the arduino
    sp = subparser.add_parser(
        'library',
        help='Operations for working with arduino libraries.'
    )
    sp.set_defaults(cmd='library')
    library_subparser = sp.add_subparsers(required=True)
    lssp = library_subparser.add_parser(
        'index',
        help='Index all libraries in a subdirectory'
    )
    lssp.add_argument(
        'target',
        metavar='DIRECTORY',
        type=str,
        help='Directory to search in'
    )

    return parser.parse_args()


def main():
    args = __parse_args()

    if args.cmd == 'compile' or args.cmd == 'all':
        from pyarduino_helper.Executor import Executor
        print('Compile')
        Executor.compile()

    if args.cmd == 'upload' or args.cmd == 'all':
        from pyarduino_helper.Executor import Executor
        print(f'Uploading {args.target}')
        Executor.upload(args.target)

    if args.cmd == 'library':
        print('Library')
        args.func(args.target)


if __name__ == '__main__':
    main()
