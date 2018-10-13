#include <iostream>
#include <cstdio>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

int main() {
    bool found = false;
    int num_cells, length_jump;
    scanf("%d %d\n", &num_cells, &length_jump);
    string line;
    getline(cin, line);
    int target = line.find('T');
    queue<string> q;
    unordered_set<string> visited;
    q.push(line);
    while(!q.empty()) {
        string line = q.front();
        q.pop();
        visited.insert(line);
        int g_idx = line.find('G');
        if(g_idx + length_jump == target || g_idx - length_jump == target) {
            found = true;
            break;
        }
        if(g_idx + length_jump < line.size() && line[g_idx+length_jump] != '#') {
            string new_line(line);
            new_line[g_idx] = '.';
            new_line[g_idx + length_jump] = 'G';
            if(visited.find(new_line) == visited.end()) {
                q.push(new_line);
            }
        }
        if(g_idx - length_jump >= 0 && line[g_idx-length_jump] != '#') {
            string new_line(line);
            new_line[g_idx] = '.';
            new_line[g_idx - length_jump] = 'G';
            if(visited.find(new_line) == visited.end()) {
                q.push(new_line);
            }
        }
    }

    if(found) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
