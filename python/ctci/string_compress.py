import sys
import collections

def string_compress(s):
    stringbuild = list()
    count = 0
    deficit = 0
    this_char = s[0]
    for c in s:
        if c == this_char:
            count += 1
        else:
            stringbuild.append(this_char)
            stringbuild.append(str(count))
            deficit -= (count - 2)
            count = 1
            this_char = c
    stringbuild.append(this_char)
    stringbuild.append(str(count))
    deficit -= (count - 2)
    return s if (deficit > 1) else "".join(stringbuild)

if __name__ == '__main__':

    for line in sys.stdin.readlines():
        line = line.strip()
        print("{} compressed is :: {}".format(line, string_compress(line)))
        print()

