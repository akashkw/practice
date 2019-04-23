#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <thread>
#include <chrono>

#include "gtest/gtest.h"

using namespace std;

/*
 * Problem Statement
 * 
 * This problem was asked by Apple.
 * 
 * Implement a job scheduler which takes in a function f and an integer n, and calls f after n milliseconds.
 */

void dispatch_delayed(function<void ()> f, int num) {
    this_thread::sleep_for(chrono::milliseconds(num));
    f();
}

void hello(ostream &w) {
    w << "Hello from this function" << endl;
}

void yello(ostream &w, int n) {
    w << "Hello from yello, you gave "<< n << endl;
}

// Solution Function
void schedule(function<void ()> f, int num) {
    thread (dispatch_delayed, f, num).detach();
}

TEST(SolutionFixture, test_1) {
    ostringstream w;
    schedule(bind(hello, ref(w)), 1500);
    sleep(2);
    ASSERT_EQ(w.str(), "Hello from this function\n");
}

TEST(SolutionFixture, test_2) {
    ostringstream w;
    schedule(bind(hello, ref(w)), 3500);
    sleep(2);
    ASSERT_EQ(w.str(), "");
    sleep(2);
}

TEST(SolutionFixture, test_3) {
    ostringstream w;
    schedule(bind(yello, ref(w), 30), 1500);
    sleep(2);
    ASSERT_EQ(w.str(), "Hello from yello, you gave 30\n");
}

TEST(SolutionFixture, test_4) {
    ostringstream w;
    schedule(bind(yello, ref(w), 30), 3500);
    sleep(2);
    ASSERT_EQ(w.str(), "");
    sleep(2);
}