import sys
si = sys.stdin.readline
n = int(si())
m = int (si())
a = list(map(int, si().split()))

def determination(height):
    last = 0
    for x in a:
        if x - last <= height:
            last = x + height
        else:
            return False
    return last >= n

l, r, ans = 0, n, n
a.sort()
while l <= r:
    mid = (l + r) // 2
    if determination(mid):
        ans = mid
        r = mid - 1
    else:
        l = mid + 1

print(ans)