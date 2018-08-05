import sys
import collections

def check_palindrome(s):
    odd_count = 0
    freq = collections.Counter()
    for c in s:
        if c != ' ':
            freq[c] += 1
            odd_count += -1 if freq[c]%2==0 else 1
    return odd_count < 2

if __name__ == '__main__':

    for line in sys.stdin.readlines():
        line = line.strip()
        print("{} is a permutation of a palindrome? :: {}".format(line, check_palindrome(line)))
        print()

