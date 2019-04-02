import unittest
import pdb

'''
Problem Statement

'''

def solution(x):
    return x + 1

class MyTest(unittest.TestCase):
    def test_1_success(self):
        # pdb.set_trace()
        self.assertEqual(solution(3), 4)

    def test_2_failure(self):
        # pdb.set_trace()
        self.assertNotEqual(solution(4), 4)
