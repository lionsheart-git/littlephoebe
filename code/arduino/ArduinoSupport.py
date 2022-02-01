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
    parser_all = subparser.add_parser(
        'all',
        help='Compile and upload a file to the arduino.'
    )
    parser_all.set_defaults(cmd='all')
    parser_all.add_argument(
        'target',
        metavar='HEX',
        type=str,
        help='Name of the hex file to upload to the arduino uno.'
    )

    # Parser for compiling a sketch
    parser_compile = subparser.add_parser(
        'compile',
        help='Compiles the cmake in the current directory.'
    )
    parser_compile.set_defaults(cmd='compile')

    # Parser for uploading a hex to the arduino
    parser_upload = subparser.add_parser(
        'upload',
        help='Upload a file to the arduino.'
    )
    parser_upload.set_defaults(cmd='upload')
    parser_upload.add_argument(
        'target',
        metavar='HEX',
        type=str,
        help='Upload a hex file to the arduino uno.'
    )

    # Parser for working with libraries a hex to the arduino
    from pyarduino_helper.Library import Library
    parser_library = subparser.add_parser(
        'library',
        help='Operations for working with arduino libraries.'
    )
    parser_library.set_defaults(cmd='library')

    subparser_library = parser_library.add_subparsers(required=True)
    parser_index = subparser_library.add_parser(
        'index',
        help='Index all libraries in a subdirectory'
    )
    parser_index.set_defaults(func=Library.index)
    parser_index.add_argument(
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
