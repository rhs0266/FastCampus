import sys
si = sys.stdin.readline
n = int(si())
a = list(map(int, si().split()))
sum = int(si())

def bin_search(a, l, r, x):
    while l <= r:
        mid = (l + r) // 2
        if a[mid] == x:
            return True
        if a[mid] < x: l = mid + 1
        else: r = mid - 1
    return False

a.sort()
ans = 0
for i in range(n - 1):
    if bin_search(a, i + 1, n - 1, sum - a[i]): ans += 1
    
print(ans)