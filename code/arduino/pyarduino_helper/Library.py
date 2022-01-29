class Library:

    @staticmethod
    def index(path: str):
        import os
        for root, dirs, files in os.walk(path):
            # print('root: ', root)
            path = root.split(os.sep)
            print((len(path) - 1) * '  ', os.path.basename(root), '/')
            for file in files:
                print(len(path) * '  ', file)
