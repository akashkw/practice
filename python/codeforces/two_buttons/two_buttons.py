
if __name__ == '__main__':
    count = 0
    start, finish = tuple(map(int, input().split()))
    if start > finish:
        count = start - finish
    else:
        while start * 2 > finish:
            start -= 1
            count += 1
        while start < finish:
            start *= 2
            count += 1
        while start != finish:
            start -= 1
            count += 1
    print(count)
