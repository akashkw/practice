# Return a new sorted merged list from K sorted lists, each with size N
# For example, if we had [[10, 15, 30], [12, 15, 20], [17, 20, 32]]
# The result should be [10, 12, 15, 15, 17, 20, 20, 30, 32]

from heapq import heappush, heappop

def merge_sorted_lists(lists):
    min_heap = list()
    sorted_list = list()
    for i, l in enumerate(lists):
        heappush(min_heap, (l[0], i, 0)) 
    while min_heap:
        val, lis, ind = heappop(min_heap)
        sorted_list.append(val)
        if ind + 1 < len(lists[lis]):
            heappush(min_heap, (lists[lis][ind+1], lis, ind+1))
    return sorted_list

if __name__ == '__main__':
    lists = [[10, 15, 30], [12, 15, 20], [17, 20, 32]]

    print(merge_sorted_lists(lists))
