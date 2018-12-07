# This problem was asked by Uber.

# Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

# For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

# Follow-up: what if you can't use division?

def product_array(data):
    left = [1] * len(data)
    right = [1] * len(data)

    for i in range(1, len(data)):
        left[i] = left[i-1] * data[i-1]
        right[-i-1] = right[-i] * data[-i]

    return [left[i] * right[i] for i in range(len(data))]

if __name__ == '__main__':
    tests = [[1, 2, 3, 4, 5],
             [3, 2, 1]]
    for test in tests:
        print(product_array(test))
