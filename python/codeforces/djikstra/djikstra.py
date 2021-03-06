from heapq import heappop, heappush
def int_line():
    return (map(int, input().split()))

nodes, edges = int_line()

graph = [[] for x in range(nodes)]

for x in range(edges):
    left, right, cost = int_line()
    left -= 1; right -= 1
    graph[left].append((right, cost))
    graph[right].append((left, cost))

visited = [False for x in range(nodes)]
previous = [-1 for x in range(nodes)]

pq = list()
heappush(pq, (0, 0, -1))
path_found = False
while pq:
    path_cost, node, prev = heappop(pq)
    if visited[node]: continue
    visited[node] = True
    previous[node] = prev
    if node == nodes-1:
        path_found = True
        break
    for nxt, cost in graph[node]:
        if not visited[nxt]:
            heappush(pq, (path_cost + cost, nxt, node))
if not path_found:
    print(-1)
    exit(0)
    quit()
path = []
current = nodes-1
while current != -1:
    path.append(str(current + 1));
    current = previous[current]
path.reverse()
print(" ".join(path))
    
