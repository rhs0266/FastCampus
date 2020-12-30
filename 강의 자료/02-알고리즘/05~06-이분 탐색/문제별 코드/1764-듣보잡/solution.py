import sys
si = sys.stdin.readline
n, m = list(map(int, si().split()))
a = sorted([si() for _ in range(n)])
b = sorted([si() for _ in range(m)])

def bin_search(a, l, r, x):
    while l <= r:
        mid = (l + r) // 2
        if a[mid] == x:
            return True
        if a[mid] < x: l = mid + 1
        else: r = mid - 1
    return False

ans = [x for x in b if bin_search(a, 0, n-1, x)]
print(len(ans))
for x in ans:
    print(x, end="")