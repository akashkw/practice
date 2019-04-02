import unittest

'''
Problem Statement

'''

def solution(x):
    return x + 1

class MyTest(unittest.TestCase):
    def test_success(self):
        self.assertEqual(solution(3), 4)

    def test_failure(self):
        self.assertNotEqual(solution(4), 4)
