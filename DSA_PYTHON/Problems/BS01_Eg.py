# Binary search examples

# Search key if present return True otherwise return False
def search_key(arr, key):

    l, r = 0, len(arr) - 1
    while l <= r:           # if r = m-1 & l = m+1 then while l <= r
        m = (l + r) // 2
        if key == arr[m]:
            return True
        if key < arr[m]:
            r = m - 1
        if key > arr[m]:
            l = m + 1

    return False


# Find key if not present then find immediate smaller
def search_key2(arr, key):
    res = None
    l, r = 0, len(arr) - 1
    while l <= r:
        m = (l + r) // 2
        if key == arr[m]:
            return arr[m]
        if key < arr[m]:
            r = m - 1
        if key > arr[m]:
            res = arr[m]
            l = m + 1

    return res


ret = search_key([5,10,15,20,25], 10)
print(ret)
ret = search_key2([5,10,15,20], 6)
print(ret)
