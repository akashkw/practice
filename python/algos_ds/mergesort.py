def mergesort(lst):
    if len(lst) <= 1:
        return lst
    lst_1 = mergesort(lst[:len(lst)//2])
    lst_2 = mergesort(lst[len(lst)//2:])
    lst_sorted = []
    ptr_1 = 0
    ptr_2 = 0
    while ptr_1 < len(lst_1) or ptr_2 < len(lst_2):
        if ptr_1 == len(lst_1):
            lst_sorted.append(lst_2[ptr_2])
            ptr_2 += 1
            continue
        if ptr_2 == len(lst_2):
            lst_sorted.append(lst_1[ptr_1])
            ptr_1 += 1
            continue
        else:
            if lst_2[ptr_2] < lst_1[ptr_1]:
                lst_sorted.append(lst_2[ptr_2])
                ptr_2 += 1
            else:
                lst_sorted.append(lst_1[ptr_1])
                ptr_1 += 1
    return lst_sorted

if __name__ == '__main__':
    l = [1,5,7,3,5,9,3]
    print(l)
    print(mergesort(l))
    l = list(range(15))
    l.reverse()
    print(l)
    print(mergesort(l))
    l = [4,67,13,6,2,565,2,3,-4]
    print(l)
    print(mergesort(l))
