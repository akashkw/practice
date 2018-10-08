#include <iostream>
#include <vector>
#include <utility>
#include <sstream>
#include <queue>
#include <stack>
using namespace std;

struct Edge {
    int prev;
    int next;
};

class Graph {
    int num_nodes;
    vector<vector<Edge>> adjacency_list;
public: 
    Graph(int n) : num_nodes(n) {
        adjacency_list.resize(n, vector<Edge>());
    }
    ~Graph() {
    }
    void add_edge(int prev, int next) {
        adjacency_list[prev].push_back(Edge{prev, next});
        adjacency_list[next].push_back(Edge{next, prev});
    }
    string bfs_traversal(int start) {
        stringstream path;
        queue<pair<int, int>> q;
        vector<bool> visited;
        visited.resize(adjacency_list.size(), false);
        q.push(pair<int, int> (start, 1));
        while(!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();
            if(!visited[current.first]) {
                visited[current.first] = true;
                path << "->(" << current.first << ", " << current.second << ")";
                for(Edge &e : adjacency_list[current.first]) {
                    q.push(pair<int, int>(e.next, current.second + 1));
                }
            }
        }
        return path.str();
    }
    string dfs_traversal(int start) {
        stringstream path;
        stack<pair<int, int>> s;
        vector<bool> visited;
        visited.resize(adjacency_list.size(), false);
        s.push(pair<int, int> (start, 1));
        while(!s.empty()) {
            pair<int, int> current = s.top();
            s.pop();
            if(!visited[current.first]) {
                visited[current.first] = true;
                path << "->(" << current.first << ", " << current.second << ")";
                for(Edge &e : adjacency_list[current.first]) {
                    s.push(pair<int, int>(e.next, current.second + 1));
                }
            }
        }
        return path.str();
    }
    operator string() {
        stringstream ss;
        for(int i = 0; i < num_nodes; i++) {
            ss << i << "-";
            for(Edge &j : adjacency_list[i]) {
                ss << "->" << j.next;
            }
            ss << endl;
        }
        return ss.str();
    }
};

ostream& operator<<(ostream &stream, Graph &graph) {
    stream << string(graph);
    return stream;
}

int main() {
    int num_graphs;
    cin >> num_graphs;
    while(num_graphs--) {
        int nodes, edges;
        scanf("%d %d", &nodes, &edges);
        Graph graph = Graph(nodes);
        while(edges--) {
            int prev, next;
            scanf("%d-%d", &prev, &next);
            graph.add_edge(prev, next);
        }
        vector<int> tests = {0, 6, 3, 7};
        cout << "-- Graph --\n" << graph << endl;
        for(int i : tests) {
            cout << "-- BFS Traversal --\n" << graph.bfs_traversal(i) << endl;
        }
        for(int i : tests) {
            cout << "-- DFS Traversal --\n" << graph.dfs_traversal(i) << endl;
        }
    }
}

