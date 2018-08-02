#include <iostream>
#include <string>
#include <cstring>
using namespace std;
    
char* urlify(char* str, int true_size) {
    true_size--;
    int end_index = true_size;
    for (int i = 0; i <= true_size; i++) {
        if (str[i] == ' ') end_index += 2;
    }
    for (int i = 0; i <= true_size; i++) {
        if(str[true_size - i] == ' ') {
            str[end_index] = '0';
            str[end_index - 1] = '2';
            str[end_index - 2] = '%';
            end_index -= 3;
        } else {
            str[end_index] = str[true_size - i];
            end_index--;
        }
    }
    return str;
}

int main() {
    string s;
    char str[30];
    while (getline(cin, s)) {
        strcpy(str, s.c_str());
        cout << "The url of " << s << " is " << urlify(str, s.size()) << endl;
    }
}
