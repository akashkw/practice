tests = int(input())

for t in range(tests):
    points = int(input())
    x = list()
    y = list()
    for p in range(points):
        x_tmp, y_tmp = (map(int, input().split()))
        x.append(x_tmp)
        y.append(y_tmp)
    x.append(x[0])
    y.append(y[0])
    ups = 0
    downs = 0
    for i in range(len(x) - 1):
        ups += y[i] * x[i+1]
        downs += x[i] * y[i+1]
    print(abs(ups-downs))

