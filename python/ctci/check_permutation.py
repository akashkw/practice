import sys
from collections import Counter

def check_permutation_hash(s1, s2):
    if len(s1) is not len(s2):
        return False
    hashmap = Counter(list(s1))
    for c in s2:
        hashmap[c] -= 1
        if hashmap[c] < 0:
            return False
    return True

def check_permutation_sort(s1, s2):
    if len(s1) is not len(s2):
        return False
    s1 = sorted(s1)
    s2 = sorted(s2)
    for i, c in enumerate(s1):
        if c is not s2[i]:
            return False
    return True

if __name__ == '__main__':

    for line in sys.stdin.readlines():
        args = tuple(line.split())
        print("{} and {} are permutations? :: {}".format(*args, check_permutation_hash(*args)))
        print("{} and {} are permutations? :: {}".format(*args, check_permutation_sort(*args)))
        print()

