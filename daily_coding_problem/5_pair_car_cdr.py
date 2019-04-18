import unittest
import pdb

'''
Problem Statement

This problem was asked by Jane Street.

cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first and last element of that pair. For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.

Given this implementation of cons:

'''
def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair
'''
Implement car and cdr.

'''

def car(pair):
    def left(a,b):
        return a
    return pair(left)

def cdr(pair):
    def right(a,b):
        return b
    return pair(right)

class MyTest(unittest.TestCase):
    def test_1_car_success(self):
        # pdb.set_trace()
        self.assertEqual(car(cons(3,4)), 3)

    def test_2_car_failure(self):
        # pdb.set_trace()
        self.assertNotEqual(car(cons(3,4)), 4)

    def test_3_cdr_success(self):
        # pdb.set_trace()
        self.assertEqual(cdr(cons(3,4)), 4)

    def test_4_cdr_failure(self):
        # pdb.set_trace()
        self.assertNotEqual(cdr(cons(3,4)), 3)