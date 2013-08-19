#Using quick-sort to find the kth smallest number
#Best O(n), Worst O(n^2)

import random

def partition(arr, left, right, pivot):
    v = arr[pivot]
    arr[pivot], arr[right - 1] = arr[right - 1], arr[pivot]
    index = left
    for i in range(left, right):
        if arr[i] <= v:
            arr[i], arr[index] = arr[index], arr[i]
            index += 1
    return index - 1

def select(arr, left, right, k):
    while right - left > 1:
        index = partition(arr, left, right, random.randint(left, right - 1))
        dist = index - left + 1
        if dist == k:
            return arr[index]
        if dist < k:
            k -= dist
            left = index + 1
        else:
            right = index
    return arr[left]

arr = [12, 3, 45, 6, 76, 89, 100, 345, 12, 456]
k = 5

print (select(arr, 0, 10, k))
