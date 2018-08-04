// Copyright 2018 Akash Kwatra

#include <iostream>
#include <chrono>

// 12
// inline sum
// Test out inline functions, as well as chrono
// Takes a number, calculates sum in different ways, reports times

struct Timer {

    std::chrono::high_resolution_clock::time_point start, end;
    std::chrono::duration<float> duration;

    Timer() {
        start = std::chrono::high_resolution_clock::now();
    }
    ~Timer() {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        float ms = duration.count() * 1000.0f;
        std::cout << "Timer took " << ms << " milliseconds" << std::endl;
    }
};

int sum(int x, int y) {
    return x + y;
}

inline int inline_sum(int x, int y) {
    return x + y;
}

int main() {
    std::cout << std::endl << "12 - inline sum" << std::endl << std::endl;

    int x, y;
    std::cout << "Please enter first number :: ";
    std::cin >> x;
    std::cout << "Please enter second number :: ";
    std::cin >> y;

    {
        Timer timer;
        std::cout << std::endl << "Expression :: sum is " << (x + y) << std::endl;
    }
    {
        Timer timer;
        std::cout << std::endl << "Inline Function :: sum is " << inline_sum(x, y) << std::endl;
    }
    {
        Timer timer;
        std::cout << std::endl << "Function ::  sum is " << sum(x, y) << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

