from collections import deque

def bfs(start, finish):
    queue = deque()
    queue.appendleft((0, start))
    while queue:
        level, val = queue.pop()
        if val == finish:
            return level
        queue.appendleft((level + 1, val - 1))
        queue.appendleft((level + 1, val * 2))

if __name__ == '__main__':
    count = 0
    start, finish = tuple(map(int, input().split()))
    print(bfs(start, finish))
