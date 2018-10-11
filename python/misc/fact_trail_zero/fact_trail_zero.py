def fact_trail_zero(n):
    count = 0
    exp = 20
    while exp > 0:
        if n >= 5**exp:
            x = n
            while x > 0:
                count += 1
                x -= 5**exp
        exp -= 1
    return count

if __name__ == '__main__':
    import sys
    for line in sys.stdin:
        print(fact_trail_zero(int(line.strip())))
