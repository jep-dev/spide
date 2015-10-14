import os
import subprocess
import sys

def main(paths):
    for path in paths:
        subprocess.Popen(path)
    """path = os.path.abspath("./spide")
    subprocess.Popen(path) """

""" If this file is executed directly... """
if __name__ == "__main__":
    if len(sys.argv) == 1:
        main([os.path.abspath("./spide")])
    else:
        main(sys.argv[1:])
