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
        adjacent[node_one - 1].push_back(node_two);
        adjacent[node_two - 1].push_back(node_one);
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
    
        Graph graph = num_nodes;
        for(int j = 0; j < num_edges; j++) {
            int node_one, node_two;
            std::cin >> node_one;
            std::cin >> node_two;
            graph.add_edge(node_one, node_two);
        }

    }

}
