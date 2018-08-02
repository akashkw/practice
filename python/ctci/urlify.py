import sys

def urlify(string, true_size):
    string = list(string)
    true_size -= 1
    end_index = true_size
    for i in range(true_size):
        end_index += 2 if string[i] == ' ' else 0
    for i in range(true_size):
        if string[true_size - i] == ' ':
            string[end_index] = '0'
            string[end_index - 1] = '2'
            string[end_index - 2] = '%'
            end_index -= 3
        else:
            string[end_index] = string[true_size - i]
            end_index -= 1
    return ''.join(string)

if __name__ == '__main__':

    for line in sys.stdin.readlines():
        line = line.strip()
        print("The url of {} is {}".format(line, urlify(line.ljust(30, ' '), len(line))))
        print()

