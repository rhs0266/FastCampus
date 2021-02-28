import sys
si = sys.stdin.readline
n = int(si())
a = sorted(list(map(int, si().split())))

def lower_bound(a, l, r, x):
    res = r + 1
    while l <= r:
        mid = (l + r) // 2
        if a[mid] >= x:
            res = mid
            r = mid - 1
        else: l = mid + 1
    return res

def upper_bound(a, l, r, x):
    res = r + 1
    while l <= r:
        mid = (l + r) // 2
        if a[mid] > x:
            res = mid
            r = mid - 1
        else: l = mid + 1
    return res

m = int(si())
b = list(map(int, si().split()))
for x in b:
    print(upper_bound(a, 0, n - 1, x) - lower_bound(a, 0, n - 1, x), end=' ')