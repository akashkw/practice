#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
using namespace std;

bool connected(vector<vector<int>> &graph) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int node = q.front(); q.pop();
        if(visited[node]) {
            continue;
        }
        visited[node] = true;
        for(int adj_node : graph[node]) {
            if(!visited[adj_node]) {
                q.push(adj_node);
            }
        }
    }
    bool connected = true;
    for(int i = 0; i < visited.size(); i++) {
        if(!visited[i] && graph[i].size() > 0) {
            connected = false;
            break;
        }
    }
    return connected;
}

string fleury(vector<vector<int>> &graph, int edges, int start_node) {
    stringstream result;
    result << start_node + 1 << " ";
    int current_node = start_node;
    while(edges--) {
        for(int i = 0; i < graph[current_node].size(); i++) {
            vector<int> &list_c = graph[current_node];
            int adj = list_c[i];
            vector<int> &list_a = graph[adj];
            list_c.erase(find(begin(list_c), end(list_c), adj));
            list_a.erase(find(begin(list_a), end(list_a), current_node));
            if(connected(graph)) {
                result << adj + 1 << " ";
                current_node = adj;
                break;
            }
            else {
                list_c.insert(begin(list_c), adj);
                list_a.insert(begin(list_a), current_node);
            }
        }
    }
    return result.str(); 
}

int main() {
    int tests;
    cin >> tests;
    while(tests--) {
        int nodes, edges;
        cin >> nodes >> edges;
        vector<vector<int>> graph(nodes);
        // populate the graph
        for(int e = 0; e < edges; e++) {
            int left, right;
            cin >> left >> right;
            //account for 1 indexing of nodes
            left--; right--;
            graph[left].push_back(right);
            graph[right].push_back(left);
        }

        int odd_count(0), start_node(0);
        for(int n = 0; n < graph.size(); n++) {
            if(graph[n].size() % 2 != 0) {
                odd_count++;
                start_node = n;
            }
        }
        if(odd_count != 0 && odd_count != 2) {
            cout << -1 << endl; exit(0);
        }

        cout << fleury(graph, edges, start_node) << endl;
    }
}
