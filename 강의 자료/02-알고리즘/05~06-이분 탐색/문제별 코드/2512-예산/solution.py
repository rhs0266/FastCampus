import sys
si = sys.stdin.readline
n = int(si())
a = list(map(int, si().split()))
m = int(si())

def determination(limit):
    sum = 0
    for x in a:
        sum += min(x, limit)
    return sum <= m

l, r, ans = 0, max(a), 0
while l <= r:
    mid = (l + r) // 2
    if determination(mid):
        ans = mid
        l = mid + 1
    else:
        r = mid - 1

print(ans)