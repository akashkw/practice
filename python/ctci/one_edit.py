import sys
import collections

def one_edit(str1, str2):
    lens = abs(len(str1) - len(str2))
    if lens == 0:
        ins_found = False
        for i,c in enumerate(str1):
            if c != str2[i]:
                if ins_found:
                    return False
                else:
                    ins_found = True
    elif lens == 1:
        if len(str1) > len(str2):
            larger = str1
            smaller = str2
        else:
            smaller = str1
            larger = str2
        shift_used = False
        s_index = 0
        l_index = 0
        while s_index < len(smaller):
            if smaller[s_index] != larger[l_index]:
                if shift_used:
                    return False
                else:
                    shift_used = True
                    l_index += 1
                    continue
            l_index += 1
            s_index += 1
    else:
        return False
    return True

if __name__ == '__main__':

    for line in sys.stdin.readlines():
        s1, s2 = line.split()
        args = (s1,s2)
        print("{} {} are one edit off? :: {}".format(*args, one_edit(*args)))
        print()

