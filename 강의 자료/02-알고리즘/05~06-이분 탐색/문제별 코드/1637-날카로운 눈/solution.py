import sys
si = sys.stdin.readline
n = int(si())
info = []
for i in range(n):
    info.append(list(map(int, si().split())))

def count(A, C, B, X):
    if X < A: return 0
    if C < X: return (C - A) // B + 1
    return (X - A) // B + 1

def determination(candidate):
    sum = 0
    for i in info:
        sum += count(i[0], i[1], i[2], candidate)
    return sum % 2 == 1

l, r, ans, ansCnt = 1, 1 << 31, 0, 0
while l <= r:
    mid = (l + r) // 2
    if determination(mid):
        ans = mid
        r = mid - 1
    else:
        l = mid + 1

if ans == 0:
    print("NOTHING")
else:
    for i in info:
        if i[0] <= ans and ans <= i[1] and (ans - i[0]) % i[2] == 0:
            ansCnt += 1
    print(ans, ansCnt)