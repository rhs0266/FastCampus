import sys
si = sys.stdin.readline
n, c = list(map(int, si().split()))
a = []
for i in range(n):
    a.append(int(si()))

def determination(D):
    cnt, last = 1, a[0]
    for i in range(1, n):
        if a[i] - last < D: continue
        last = a[i]
        cnt += 1
    return cnt >= c

a.sort()
l, r, ans = 1, 1000000000, 0
while l <= r:
    mid = (l + r) // 2
    if determination(mid):
        ans = mid
        l = mid + 1
    else:
        r = mid - 1

print(ans)