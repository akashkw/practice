from heapq import heappush, heappop

def i_in():
    return (map(int, input().split()))

nodes, edges, start = i_in()
start -= 1

graph = [[] for x in range(nodes)]
edge_list = []
shortest_path = [float('inf') for x in range(nodes)]

for x in range(edges):
    left, right, cost = i_in()
    left -= 1; right -= 1
    graph[left].append((right, cost))
    graph[right].append((left, cost))
    edge_list.append((left, right, cost))

l, = i_in()

pq = [(0, start)]
while pq:
    path_cost, node = heappop(pq)
    if shortest_path[node] < path_cost: continue
    shortest_path[node] = path_cost
    for adj, cost in graph[node]:
        if cost + path_cost < shortest_path[adj]:
            shortest_path[adj] = cost + path_cost
            heappush(pq, (shortest_path[adj], adj))

silos = 0
for p in shortest_path:
    silos += 1 if p == l else 0

for left, right, cost in edge_list:
    if shortest_path[left] < l and shortest_path[left] + cost > l:
        silo_dist = l - shortest_path[left]
        silos += 1 if shortest_path[right] + (cost - silo_dist) >= shortest_path[left] + silo_dist else 0
    if shortest_path[right] < l and shortest_path[right] + cost > l:
        silo_dist = l - shortest_path[right]
        silos += 1 if shortest_path[left] + (cost - silo_dist) > shortest_path[right] + silo_dist else 0
print(silos)


