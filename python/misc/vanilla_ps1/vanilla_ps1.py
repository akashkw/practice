from collections import deque

tests = int(input())
for t in range(tests):
    nodes, edges, start, distance = tuple(map(int, input().split()))
    start -= 1
    graph = [list() for node in range(nodes)]
    visited = [False for node in range(nodes)]
    for e in range(edges):
        left, right = tuple(map(int, input().split()))
        left -= 1
        right -= 1
        graph[left].append(right)
        graph[right].append(left)

    queue = deque()
    # connected components
    num_components = 0
    while False in visited:
        queue.appendleft(visited.index(False))
        num_components += 1
        while queue:
            node = queue.pop()
            if visited[node]: continue
            visited[node] = True
            for a_node in graph[node]:
                if not visited[a_node]:
                    queue.appendleft(a_node)
    # bfs traversal
    num_visited = 0
    visited = [False for node in range(nodes)]
    queue.appendleft((start, 0))
    while queue:
        node, level = queue.pop()
        if level > distance: break
        if visited[node]: continue
        visited[node] = True
        num_visited += 1
        for a_node in graph[node]:
            if not visited[a_node]:
                queue.appendleft((a_node, level + 1))
    print(f'{num_components} {num_visited}')

        
