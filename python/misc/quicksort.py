def quicksort(lst):
    if len(lst) <= 1:
        return lst
    smaller = [x for x in lst[1:] if x <= lst[0]]
    larger = [x for x in lst[1:] if x > lst[0]]
    return quicksort(smaller) + [lst[0]] + quicksort(larger)

if __name__ == '__main__':
    l = [1,5,7,3,5,9,3]
    print(l)
    print(quicksort(l))
    l = list(range(15))
    l.reverse()
    print(l)
    print(quicksort(l))
    l = [4,67,13,6,2,565,2,3,-4]
    print(l)
    print(quicksort(l))
