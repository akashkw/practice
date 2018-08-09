def quicksort(lst):
    if len(lst) <= 1:
        return lst
    smaller = [x for x in lst[1:] if x <= lst[0]]
    larger = [x for x in lst[1:] if x > lst[0]]
    return quicksort(smaller) + lst[0] + quicksort(larger)

if __name__ == '__main__':
    l = [1,5,7,3,5,9,3]
    quicksort(l)
    print(l)
