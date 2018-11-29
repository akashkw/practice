from collections import deque

def bfs(source, sink, res_graph, parents):
    visited = [False] * len(res_graph)
    visited[source] = True
    queue = deque()
    queue.appendleft(source)
    while queue:
        u = queue.pop()
        for v, c in enumerate(res_graph[u]):
            if not visited[v] and c > 0:
                visited[v] = True
                parents[v] = u
                queue.appendleft(v)
    return visited[sink]

def edmonds_karp(source, sink, graph):
    res_graph = [[v for v in u] for u in graph]
    parents = [-1] * len(res_graph)
    max_flow = 0
    while bfs(source, sink, res_graph, parents):
        bottleneck = float('inf')
        v = sink
        while v != source:
            u = parents[v]
            bottleneck = min(bottleneck, res_graph[u][v])
            v = u
        v = sink
        while v != source:
            u = parents[v]
            res_graph[u][v] -= bottleneck
            res_graph[v][u] += bottleneck
            v = u
        max_flow += bottleneck
    return max_flow

if __name__ == '__main__':
    tests = int(input())
    for t in range(tests):
        nodes, edges, source, sink = (map(int, input().split()))
        graph = [[0 for v in range(nodes)] for u in range(nodes)]
        for e in range(edges):
            u, v, c = (map(int, input().split()))
            graph[u][v] = c
        print(edmonds_karp(source, sink, graph))

