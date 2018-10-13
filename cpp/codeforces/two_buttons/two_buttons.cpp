#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

long long bfs(long long start, long long finish) {
    long long count = 0;
    queue<pair<int, int>> queue;
    unordered_set<int> visited;
    queue.push(pair<int, int>(0, start));
    while(!queue.empty()) {
        pair<int, int> item = queue.front();
        queue.pop();
        if(visited.find(item.second) != end(visited)){
           continue; 
        }
        visited.insert(item.second);
        if(item.second == finish) {
            return item.first;
        }
        if(visited.find(item.second - 1) == end(visited)){
            queue.push(pair<int, int>(item.first + 1, item.second - 1));
        }
        if(visited.find(item.second * 2) == end(visited)){
            queue.push(pair<int, int>(item.first + 1, item.second * 2));
        }
    }

}

int main() {

    long long first, second;
    scanf("%lld %lld", &first, &second);
    cout << bfs(first, second) << endl;
}
