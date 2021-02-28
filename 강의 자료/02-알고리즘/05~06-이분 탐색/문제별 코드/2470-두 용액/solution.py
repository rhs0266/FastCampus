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

best_sum = 1 << 31
v1, v2 = 0, 0
for l in range(n - 1):
    candidate = lower_bound(a, l + 1, n - 1, -a[l])
    if l < candidate - 1 and abs(a[l] + a[candidate - 1]) < best_sum:
        best_sum = abs(a[l] + a[candidate - 1])
        v1, v2 = a[l], a[candidate - 1]
    
    if candidate < n and abs(a[l] + a[candidate]) < best_sum:
        best_sum = abs(a[l] + a[candidate])
        v1, v2 = a[l], a[candidate]

print(v1, v2)