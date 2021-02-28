import sys
si = sys.stdin.readline

def lower_bound(a, l, r, x):
    res = l - 1
    while l <= r:
        mid = (l + r) // 2
        if a[mid] < x:
            res = mid
            l = mid + 1
        else: r = mid - 1
    return res

def solve():
    b.sort()
    ans = 0
    for x in a:
        ans += lower_bound(b, 0, m - 1, x) + 1
    print(ans)

TT = int(si())
for _ in range(TT):
    n, m = list(map(int, si().split()))
    a = list(map(int, si().split()))
    b = list(map(int, si().split()))
    solve()