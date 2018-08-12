#include <iostream>
#include <list>

class Graph {
    int num_nodes;
    std::list<int>* adjacent;
public:
    Graph(int nodes) : num_nodes(nodes) {
        adjacent = new std::list<int>[num_nodes];
    }
    ~Graph() {
        delete[] adjacent;
    }
    void add_edge(int node_one, int node_two) {
        adjacent[node_one].push_back(node_two);
        adjacent[node_two].push_back(node_one);
    }
    void print_graph() {
        for(int i = 0; i < num_nodes; i++) {
            std::cout << "[" << i+1 << "]->";
            for(int num : adjacent[i]) {
                std::cout << num << "->";
            }
            std::cout << "*" << std::endl;
        }
    }
    int connected_components() {
        bool* visited = new bool[num_nodes];
        for(int i = 0; i < num_nodes; i++) {
            visited[i] = false;
        }
        std::list<int> queue;
        int components = 0;
        for(int i = 0; i < num_nodes; i++) {
            if(!adjacent[i].empty() && !visited[i]) {
                visited[i] = true;
                queue.push_back(i);
                components++;
            }
            while(!queue.empty()) {
                int node = queue.front();
                queue.pop_front();
                for(int adj_node : adjacent[node]) {
                    if(!visited[adj_node]) {
                        visited[adj_node] = true;
                        queue.push_back(adj_node);
                    }
                }
            }
        }
        delete visited;
        return components;
    }

    int nodes_reachable(int start_node, int furthest_dist) {
        bool* visited = new bool[num_nodes];
        for(int i = 0; i < num_nodes; i++) {
            visited[i] = false;
        }
        std::list<int> queue;
        int node_count = 1;
        int path_length = 0;
        visited[start_node] = true;
        queue.push_back(start_node);
        
        while(!queue.empty() && node_count <= furthest_dist) {
            int node = queue.front();
            queue.pop_front();
            for(int adj_node : adjacent[node]) {
                if(!visited[adj_node]) {
                    visited[adj_node] = true;
                    queue.push_back(adj_node);
                    node_count++;
                }
            }
            path_length++;
        }

        delete visited;
        return node_count;
    }
};

int main() {

    int num_tests;
    std::cin >> num_tests;
    for(int i = 0; i < num_tests; i++) {
        int num_nodes, num_edges, start_node, furthest_dist; 
        std::cin >> num_nodes;
        std::cin >> num_edges;
        std::cin >> start_node;
        std::cin >> furthest_dist;
    
        Graph* graph = new Graph(num_nodes);
        for(int j = 0; j < num_edges; j++) {
            int node_one, node_two;
            std::cin >> node_one;
            std::cin >> node_two;
            graph->add_edge(node_one - 1, node_two - 1);
        }
        std::cout << graph->connected_components() << " " << graph->nodes_reachable(start_node - 1, furthest_dist) << std::endl;
        delete graph;
    }

}
