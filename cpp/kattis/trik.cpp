#include <iostream>
using namespace std;

#define pl(n) cout << n << endl
    
int main() {
    int ball_i = 1;
    string moves;
    cin >> moves;
    for(char c : moves) {
        switch (c) {
            case 'A':
                ball_i = (ball_i == 1 ? 2 : (ball_i == 2 ? 1 : ball_i));
                break;
            case 'B':
                ball_i = (ball_i == 2 ? 3 : (ball_i == 3 ? 2 : ball_i));
                break;
            case 'C':
                ball_i = (ball_i == 1 ? 3 : (ball_i == 3 ? 1 : ball_i));
                break;
        }
    }
    pl(ball_i);
}
