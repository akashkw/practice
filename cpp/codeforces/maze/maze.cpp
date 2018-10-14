#include <iostream>
#include <vector>
#include <stack>
#include <tuple>
using namespace std;

int main() {
    int height, width, walls;
    scanf("%d %d %d", &height, &width, &walls);

    int num_seen(0), total_spots(0);

    vector<vector<char>> maze(height, vector<char>(width, '\0'));
    vector<vector<bool>> visited(height, vector<bool>(width, false));
    
    pair<int, int> start;

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            char c;
            cin >> c;
            if(c == '.') {
                c = 'X';
                total_spots++;
                start = make_pair(i, j);
            }
            maze[i][j] = c;
        }
    }

    stack<pair<int, int>> stack;
    stack.push(start);
    
    vector<int> di = {-1, 0, 1, 0};
    vector<int> dj = {0, -1, 0, 1};

    while(!stack.empty()) {
        int i, j; tie(i, j) = stack.top(); stack.pop();
        if(i < 0 || j < 0 || i >= height || j >= width || visited[i][j] || num_seen == total_spots - walls) {
            continue;
        }
        if(maze[i][j] == 'X') {
            visited[i][j] = true;
            num_seen++;
            maze[i][j] = '.';
            for(int x = 0; x < 4; x++) {
                stack.push(make_pair(i + di[x], j + dj[x]));
            }
        }
    }

    for(const vector<char> &row : maze) {
        for(const char &c : row) {
            cout << c;
        }
        cout << endl;
    }
}

