#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include <climits>
using namespace std;

template<typename T> using min_pq = priority_queue<T, vector<T>, greater<T>>;

int main() {
    int nodes, edges, start;
    cin >> nodes >> edges >> start;
    start--;
    
    vector<vector<pair<int, int>>> graph(nodes);
    vector<int> shortestpath(nodes, INT_MAX >> 1);
    vector<tuple<int, int, int>> edge_list(edges);

    for(int i = 0; i < edges; i++) {
        int left, right, cost;
        cin >> left >> right >> cost;
        left--; right--;
        graph[left].push_back({right, cost});
        graph[right].push_back({left, cost});
        edge_list[i] = {left, right, cost};
    }
    int l;
    cin >> l;

    min_pq<pair<int, int>> pq;
    pq.push({0, start});
    
    while(!pq.empty()) {
        int path_cost, node; tie(path_cost, node) = pq.top(); pq.pop();
        if(shortestpath[node] < path_cost) continue;
        shortestpath[node] = path_cost;
        for(auto &e : graph[node]) {
            int adj = e.first, cost = e.second;
            if(shortestpath[adj] > path_cost + cost) {
                pq.push({path_cost + cost, adj});
            }
        }
    }

    int silos = 0;
    for(int &i : shortestpath) {
        silos += i==l ? 1:0;
    }

    for(auto &e : edge_list) {
        int left, right, cost; tie(left, right, cost) = e;
        if(shortestpath[left] < l && shortestpath[left] + cost > l) {
            int silo_dist = l - shortestpath[left];
            if(shortestpath[right] + cost - silo_dist >= l) {
                silos++;
            }
        }
        if(shortestpath[right] < l && shortestpath[right] + cost > l) {
            int silo_dist = l - shortestpath[right];
            if(shortestpath[left] + cost - silo_dist > l) {
                silos++;
            }
        }
    }
    cout << silos;
}
