import queue

class Edge:
    def __init__(self, p, n, c=0):
        self.previous = p
        self.next = n
        self.cost = c

class Graph:
    def __init__(self, size):
        self.num_nodes = size
        self.adjacency_list = [list() for x in range(size)]

    def add_edge(self, p, n, c=0):
        self.adjacency_list[p].append(Edge(p, n, c))
        self.adjacency_list[n].append(Edge(n, p, c))

    def __str__(self):
        string = list()
        for i, lst in enumerate(self.adjacency_list):
            string.append(f'{i}-')
            for edge in lst:
                string.append(f'->{edge.next}')
            string.append('\n')
        return ''.join(map(str, string))

    def bfs_traversal(self, start):
        string = list()
        q = queue.Queue()
        visited = [False for x in range(self.num_nodes)]
        q.put((start, 1))
        while not q.empty():
            node, level = q.get()
            if not visited[node]:
                visited[node] = True
                string.append(f'->({node}, {level})')
                for edge in self.adjacency_list[node]:
                    q.put((edge.next, level + 1))
        return ''.join(map(str, string))

    def dfs_traversal(self, start):
        string = list()
        q = queue.LifoQueue()
        visited = [False for x in range(self.num_nodes)]
        q.put((start, 1))
        while not q.empty():
            node, level = q.get()
            if not visited[node]:
                visited[node] = True
                string.append(f'->({node}, {level})')
                for edge in self.adjacency_list[node]:
                    q.put((edge.next, level + 1))
        return ''.join(map(str, string))


if __name__ == '__main__':
    num_graphs = int(input())
    for i in range(num_graphs):
        nodes, edges = map(int, input().split())
        graph = Graph(nodes)
        for j in range(edges):
            p, n = map(int, input().split('-'))
            graph.add_edge(p, n)
        print(f'-- Graph --\n{str(graph)}')
        for i in [0, 6, 3, 7]:
            print(f'-- BFS Traversal --\n{graph.bfs_traversal(i)}')
        for i in [0, 6, 3, 7]:
            print(f'-- DFS Traversal --\n{graph.dfs_traversal(i)}')

