import sys

def isunique_hash(line):
    hashset = set()
    for c in line:
        if c in hashset:
            return False
        hashset.add(c)
    return True

def isunique_bits(line):
    ascii_table = [False for n in range(256)]
    for c in line:
        if ascii_table[ord(c)]:
            return False
        ascii_table[ord(c)] = True
    return True

def isunique_sort(line):
    s_line = sorted(line)
    for i in range(len(line)-1):
        if line[i] == line[i+1]:
            return False
    return True

if __name__ == '__main__':

    for line in sys.stdin.read().split():
        print("{} is unique? :: {}".format(line, isunique_hash(line)))
        print("{} is unique? :: {}".format(line, isunique_bits(line)))
        print("{} is unique? :: {}".format(line, isunique_sort(line)))
        print()
