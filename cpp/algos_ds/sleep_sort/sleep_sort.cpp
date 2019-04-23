#include <iostream>  
#include <vector>  
#include <chrono>     
#include <algorithm>     
#include <sstream>     
#include <string>     
#include <functional>     
#include <thread>     
  
using namespace std;

template <typename T> string vec_string(const vector<T> &vec) {
    ostringstream out;
    out << "[";
    for(size_t i = 0; i < vec.size(); ++i)
        out << vec[i] << ",]"[i==vec.size()-1];
    return out.str();
}

void sleep_push(vector<int> &sorted, const int &i) {
    this_thread::sleep_for(chrono::milliseconds(20*i));
    sorted.push_back(i);
}

int main () 
{ 
    vector<int> unsorted, sorted;
    int i;
    while(cin >> i)
        unsorted.push_back(i);

    for(const int &i : unsorted) {
        thread (sleep_push, ref(sorted), cref(i)).detach();
    }
    this_thread::sleep_for(chrono::milliseconds(50 * *(max_element(begin(unsorted), end(unsorted)))));
    
    cout << "UNSORTED ARRAY : " << vec_string<int>(unsorted) << endl;
    cout << "SORTED ARRAY : " << vec_string<int>(sorted) << endl;

} 
