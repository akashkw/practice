# This problem was recently asked by Google.

# Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

# For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

# Bonus: Can you do this in one pass?

def two_sum(nums, k):
    seen = set()
    for n in nums:
        if k-n not in seen:
            seen.add(n)
        else:
            return True
    return False

if __name__ == '__main__':
    k = 17
    nums = [10, 15, 3, 7]
    print(two_sum(nums, k))
