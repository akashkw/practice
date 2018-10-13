#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <tuple>
using namespace std;

class Maze {
    vector<vector<char>> maze_;
    vector<vector<bool>> visited_;
public:
    Maze(int height, int width) {
        maze_ = vector<vector<char>>(height, vector<char>(width, '\0'));
        visited_ = vector<vector<bool>>(height, vector<bool>(width, false));
    }
    vector<char>& operator[](int i) {
        return maze_[i];
    }
    bool visited(int i, int j) const {
        return visited_[i][j];
    }
    void visit(int i, int j) {
        visited_[i][j] = true;
    }
    operator string() const {
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

ostream& operator<<(ostream &_stream, const Maze &_maze) {
    _stream << string(_maze);
    return _stream;
}

int main() {

    int height, width, num_walls;
    int num_visited(0), num_spots(0);
    scanf("%d %d %d", &height, &width, &num_walls);

    Maze maze(height, width);
    pair<int, int> start;

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            char c;
            cin >> c;
            if(c == '.') {
                c = 'X';
                num_spots++;
            }
            maze[i][j] = c;
            start = make_pair(i, j);
        }
    }

    stack<pair<int, int>> stack;
    stack.push(start);
    
    while(!stack.empty()) {
        int i, j; tie(i, j) = stack.top(); stack.pop();
        if(num_visited == num_spots - num_walls || maze.visited(i, j)) {
            continue;
        }
    }

    cout << maze;   
}

