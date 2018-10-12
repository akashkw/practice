
if __name__ == '__main__':
    input()
    l = list(map(int, input().split()))
    l.sort()
    for v in l:
        print(f'{v} ', end='')
