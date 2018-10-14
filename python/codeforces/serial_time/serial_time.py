from collections import deque

h, l, w = tuple(map(int, input().split()))
di = [1, -1, 0, 0, 0, 0]
dj = [0, 0, 1, -1, 0, 0]
dk = [0, 0, 0, 0, 1, -1]

plate = [[['\0' for k in range(w)] for j in range(l)] for i in range(h)]
visited = [[[False for k in range(w)] for j in range(l)] for i in range(h)]

for x in range(h):
    input()
    for y in range(l):
        plate[x][y] = list(input())
input()
x, y = tuple(map(int, input().split()))

stack = deque()
stack.append((0, x-1, y-1))

while stack:
    i, j, k = stack.pop()
    if visited[i][j][k] or plate[i][j][k] == '#': continue
    visited[i][j][k] = True
    for x in range(6):
        n_i = i + di[x]
        n_j = j + dj[x]
        n_k = k + dk[x]
        if n_i > -1 and n_j > -1 and n_k > -1 and n_i < h and n_j < l and n_k < w and not visited[n_i][n_j][n_k]:
            stack.append((n_i, n_j, n_k))

print(sum([sum([row.count(True) for row in level]) for level in visited]))
