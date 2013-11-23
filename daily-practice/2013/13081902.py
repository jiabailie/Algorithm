#Using quick-sort and median-of-median to find the kth smallest number
#Best O(n), Worst O(n)

import heapq

def partition(arr, left, right, pivot):
    index = left
    for i in range(left, right):
        if arr[i] <= pivot:
            arr[i], arr[index] = arr[index], arr[i]
            index += 1
    return index - 1

def select_heap(arr, left, right, k):
    tmp = arr[left : right]
    heapq.heapify(tmp)
    [heapq.heappop(tmp) for i in range(k - 1)]
    return heapq.heappop(tmp)

def median(arr, left, right):    
    num = int((right - left - 1) / 5)
    if num == 0:
        return ((arr[left] < arr[right]) and arr[left] or arr[right])
    medians = [0] * num
    for i in range (num):
        sub_left = left + i * 5
        sub_right = sub_left + 5
        if sub_right > right:
            sub_right = right
        m_index = select_heap(arr, sub_left, sub_right, int((sub_right - sub_left) / 2))
        medians[i] = m_index
    return select_heap(medians, 0, num, int(num / 2))

def select(arr, left, right, k):
    while right - left > 1:
        pivot = median(arr, left, right)
        index = partition(arr, left, right, pivot)
        dist = index - left + 1
        if dist == k:
            return arr[index]
        if dist < k:
            k -= dist
            left = index + 1
        else:
            right = index
    return arr[left]

arr = [34, 23, 1, 567, 1000, 456, 231, 89, 7, 458, 91]
k = 5

print (select(arr, 0, 11, 6))
