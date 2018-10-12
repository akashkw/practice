def fact_trail_zero(n):
    factor = 5
    count = 0
    while(n/factor >= 1):
        count += int(n/factor)
        factor *= 5
    return count

if __name__ == '__main__':
    import sys
    for line in sys.stdin:
        print(fact_trail_zero(int(line.strip())))
