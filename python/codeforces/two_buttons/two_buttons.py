from collections import deque

def bfs(start, finish):
    queue = deque()
    visited = set()
    item = (0, start)
    queue.appendleft(item)
    while queue:
        level, val = queue.pop()
        if val in visited:
            continue
        visited.add(val)
        if val == finish:
            return level
        if val - 1 > -1 and val - 1 not in visited:
            queue.appendleft((level + 1, val - 1))
        if val * 2 < finish + 2 and val * 2 not in visited:
            queue.appendleft((level + 1, val * 2))

if __name__ == '__main__':
    count = 0
    start, finish = tuple(map(int, input().split()))
    print(bfs(start, finish))
