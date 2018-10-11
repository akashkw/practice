def quicksort(lst):
    if len(lst) <= 1:
        return lst
    smaller = [v for v in lst[1:] if v <= lst[0]]
    larger = [v for v in lst[1:] if v > lst[0]]
    return quicksort(smaller) + [lst[0]] + quicksort(larger)

if __name__ == '__main__':
    num_tests = int(input())
    for x in range(num_tests):
        l = list(map(int, input().split()))
        print(f"Test {x+1}:\n{l}\n{quicksort(l)}")
