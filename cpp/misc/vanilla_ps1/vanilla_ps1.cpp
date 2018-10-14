#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {
    int tests;
    cin >> tests;
    while(tests--) {
        int nodes, edges, start, distance;
        scanf("%d %d %d %d", &nodes, &edges, &start, &distance);
        start--;
        vector<vector<int>> graph = vector<vector<int>>(nodes, vector<int>());
        for(int i = 0; i < edges; i++) {
           int left, right;
           cin >> left >> right;
           left--; right--;
           graph[left].push_back(right);
           graph[right].push_back(left);
        }
        int components = 0;
        vector<bool> visited = vector<bool>(nodes, false);
        queue<int> q1;
        while(find(begin(visited), end(visited), false) != end(visited)) {
            components++;
            q1.push(find(begin(visited), end(visited), false) - begin(visited));
            while(!q1.empty()) {
                int node = q1.front(); q1.pop();
                visited[node] = true;
                for(const int &adj_node : graph[node]) {
                    if(!visited[adj_node]) q1.push(adj_node);
                }
            }
        }
        visited = vector<bool>(nodes, false);
        queue<pair<int, int>> q2;
        int num_reachable_nodes = 0;
        q2.push(make_pair(start, 0));
        while(!q2.empty()) {
            int node, level; tie(node, level) = q2.front(); q2.pop();
            if(level > distance) break;
            if(visited[node]) continue;
            num_reachable_nodes++;
            visited[node] = true;
            for(const int adj_node : graph[node]) {
                q2.push(make_pair(adj_node, level+1));
            }
        }
        
        printf("%d %d\n", components, num_reachable_nodes);
    }
}
