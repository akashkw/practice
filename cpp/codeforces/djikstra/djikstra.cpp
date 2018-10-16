#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <sstream>
#include <algorithm>
using namespace std;

struct Dkq {
    int node;
    int prev;
    int path_cost;
    bool operator<(const Dkq &other) const {
        return path_cost > other.path_cost;
    }
    tuple<int, int, int> unpack() const {
        return make_tuple(node, prev, path_cost);
    }
};

int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<pair<int, int>>> graph(nodes);
    vector<bool> visited(graph.size(), false);
    vector<int> previous(graph.size(), -1);

    for(int i = 0; i < edges; i++) {
        int left, right, cost;
        cin >> left >> right >> cost;
        left--; right--;
        graph[left].push_back(make_pair(right, cost));
        graph[right].push_back(make_pair(left, cost));
    }

    priority_queue<Dkq> pq;
    pq.push(Dkq{0,-1,0});
    
    bool path_exists = false;

    while(!pq.empty()) {
        int node, prev, path_cost; tie(node, prev, path_cost) = pq.top().unpack(); pq.pop();
        if(visited[node]) continue;
        visited[node] = true;
        previous[node] = prev;
        if(node == nodes-1) {
            path_exists = true;
            break;
        }
        for(const pair<int, int> &p : graph[node]) {
            int next, cost; tie(next, cost) = p;
            if(!visited[next]) {
                pq.push(Dkq{next, node, path_cost + cost});
            }
        }
    }
    if(!path_exists) cout << -1, exit(0);
    vector<int> path;
    int current = nodes-1;
    while(current != -1) {
        path.push_back(current);
        current = previous[current];
    }
    reverse(begin(path), end(path)); 
    for(const int &i : path) cout << i+1 << " ";
}
