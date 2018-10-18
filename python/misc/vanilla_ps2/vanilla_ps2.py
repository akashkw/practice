from heapq import heappush, heappop

def line(T):
    return (map(T, input().split()))

if __name__ == '__main__':
    tests, = line(int)
    for t in range(tests):

        nodes, edges = line(int)
        graph = [[] for x in range(nodes)]
        visited = set()

        for x in range(edges):
            start, end, speed, distance = line(int)
            start -= 1; end -= 1
            graph[start].append((distance / speed, end))

        pq = [(0, 0)]

        while pq:
            path_cost, node = heappop(pq)
            if node in visited: continue
            visited.add(node)
            if node == nodes - 1:
                print(int(path_cost))
                break
            for cost, adj in graph[node]:
                if adj not in visited:
                    heappush(pq, (cost + path_cost, adj))


