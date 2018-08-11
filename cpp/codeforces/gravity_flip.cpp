#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> cols;
    for(int i = 0; i < n; i++){
      int tmp;
      std::cin >> tmp;
      cols.push_back(tmp);
    }
    std::sort(cols.begin(), cols.end());
    for(const int &x : cols){
      std::cout << x << " ";
    }
}
