
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
