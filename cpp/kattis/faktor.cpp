#include <iostream>
using namespace std;

#define pl(n) cout << n << endl
    
int main() {
    int num_articles, impact;
    cin >> num_articles;
    cin >> impact;

    pl((num_articles * (impact-1)) + 1);
}
