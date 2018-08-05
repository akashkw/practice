import sys

def urlify(s, true_size):
    s = list(s)
    trueindex = true_size-1
    newindex = trueindex + (2*s[:true_size].count(' '))
    while newindex >= 0:
        while trueindex >= 0:
            if s[trueindex] == ' ':
                s[newindex] = '0'
                s[newindex - 1] = '2'
                s[newindex - 2] = '%'
                newindex -= 3
            else:   
                s[newindex] = s[trueindex]
                newindex -= 1
            trueindex -= 1
    return "".join(s)

if __name__ == '__main__':

    for line in sys.stdin.readlines():
        line = line.strip()
        print("The url of {} is {}".format(line, urlify(line.ljust(30, ' '), len(line))))
        print()

