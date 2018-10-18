#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

template <typename T> using min_pq = priority_queue<T, vector<T>, greater<T>>;

int main() {
    int tests;
    cin >> tests;
    while(tests--) {
        int nodes, edges;
        cin >> nodes >> edges;
        vector<vector<pair<float, int>>> graph(nodes);
        for(int i = 0; i < edges; i++) {
             int start, end, speed_limit, length;
             cin >> start >> end >> speed_limit >> length;
             start--, end--;
             graph[start].push_back({(float)length / speed_limit, end});
        }

        min_pq<pair<float, int>> pq;
        vector<bool> visited(nodes, false);
        pq.push({0, 0});
        
        while(!pq.empty()) {
            float path_cost; int node;
            tie(path_cost, node) = pq.top();
            pq.pop();
            if(visited[node]) continue;
            visited[node] = true;
            if (node == nodes-1) {
                cout << (int)path_cost;
                break;
            }
            for(auto &p : graph[node]) {
                float cost; int adj;
                tie(cost, adj) = p;
                if(!visited[adj]) {
                    pq.push({path_cost + cost, adj});
                }
            }
        }
    }


}
