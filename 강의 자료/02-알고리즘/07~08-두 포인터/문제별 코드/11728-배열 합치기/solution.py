import sys
si = sys.stdin.readline
n, m = list(map(int, si().split()))
a = list(map(int, si().split()))
b = list(map(int, si().split()))
L, R = 0, 0
while L < n and R < m:
    if a[L] <= b[R]:
        print(a[L], end=' ')
        L += 1
    else:
        print(b[R], end=' ')
        R += 1
while L < n:
    print(a[L], end=' ')
    L += 1
while R < m:
    print(b[R], end=' ')
    R += 1
