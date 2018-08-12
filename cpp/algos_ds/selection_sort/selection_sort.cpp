
#include <iostream>
#include <array>
#include <climits>


void print_array(std::array<int, 7>& arr) {
    std::cout << "{ ";
    for ( int i = 0; i < arr.size(); i++ ) {
       std::cout << arr[i] << " ";
    }
    std::cout << "}" << std::endl;
}

void selection_sort(std::array<int, 7>& unsorted) {
    for ( int i = 0; i < unsorted.size(); i++ ) {
        int smallest = i;
        for(int j = i; j < unsorted.size(); j++) {
            if(unsorted[j] < unsorted[smallest]) {
                smallest = j;
            }
        }
        int tmp = unsorted[i];
        unsorted[i] = unsorted[smallest];
        unsorted[smallest] = tmp;
    }
}


int main() {

    std::array<int, 7> arr = { 4, 8, 34, 6, 23, 7, 12};

    print_array(arr);
    selection_sort(arr);
    
    print_array(arr);

}
