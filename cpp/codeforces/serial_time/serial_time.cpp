#include <iostream>
#include <vector>
#include <stack>
#include <tuple>
using namespace std;

int main() {
    int h, l, w;
    cin >> h >> l >> w;
    
    vector<vector<vector<char>>> plate(h, vector<vector<char>>(l, vector<char>(w, '\0')));
    vector<vector<vector<bool>>> visited(h, vector<vector<bool>>(l, vector<bool>(w, false)));
    vector<int> di = {1, -1, 0, 0, 0, 0};
    vector<int> dj = {0, 0, -1, 1, 0, 0};
    vector<int> dk = {0, 0, 0, 0, 1, -1};
    
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < l; j++) {
            for(int k = 0; k < w; k++) {
                cin >> plate[i][j][k];
            }
        }
    }

    int x, y;
    cin >> x >> y;
    x--; y--;
    
    stack<tuple<int, int, int>> stacc;
    stacc.push(make_tuple(0, x, y));

    while(!stacc.empty()) {
       int i, j, k; tie(i, j, k) = stacc.top(); stacc.pop(); 
       if(visited[i][j][k] || plate[i][j][k] == '#') continue;
       visited[i][j][k] = true;
       for(int x = 0; x < 6; x++) {
           int n_i = i + di[x];
           int n_j = j + dj[x];
           int n_k = k + dk[x];
           if(n_i > -1 && n_j > -1 && n_k > -1 && n_i < h && n_j < l && n_k < w && !visited[n_i][n_j][n_k]) {
                stacc.push(make_tuple(n_i, n_j, n_k));
           }
       }
    }

    int num_visited = 0;
    for(auto &x : visited) {
        for(auto &y : x) {
            for(const bool &z : y) {
                num_visited += (z) ? 1:0;
            }
        }
    }
    cout << num_visited << endl;
}
