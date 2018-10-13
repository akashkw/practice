#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Maze {
    vector<vector<char>> maze_;
public:
    Maze(int height, int width) {
        maze_ = vector<vector<char>>(height, vector<char>(width, '\0'));
    }
    Maze(const Maze &_other) {
        maze_ = _other.maze_;
    }
    vector<char>& operator[](int i) {
        return maze_[i];
    }
    operator string() {
        stringstream ss;
        for(const vector<char> &v : maze_) {
            for(const char &c : v) {
                ss << c;
            }
            ss << '\n';
        }
        return ss.str();
    }
};

int main() {
    int height, width, num_walls;
    scanf("%d %d %d", &height, &width, &num_walls);
    Maze maze(height, width);
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            char c;
            cin >> c;
            maze[i][j] = c;
        }
    }
    
}

