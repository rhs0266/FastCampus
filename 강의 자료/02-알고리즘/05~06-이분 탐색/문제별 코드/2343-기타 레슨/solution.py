import sys
si = sys.stdin.readline
n, m = list(map(int, si().split()))
a = list(map(int, si().split()))

def determination(len):
    cnt, sum = 1, 0
    for x in a:
        if sum + x > len:
            cnt += 1
            sum = x
        else:
            sum += x
    return cnt <= m


l, r, ans = max(a), 1000000000, 0
while l <= r:
    mid = (l + r) // 2
    if determination(mid):
        ans = mid
        r = mid - 1
    else:
        l = mid + 1

print(ans)