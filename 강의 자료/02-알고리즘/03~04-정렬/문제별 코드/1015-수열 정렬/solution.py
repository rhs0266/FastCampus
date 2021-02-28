import sys

n = int(sys.stdin.readline())
a = list(map(int, sys.stdin.readline().split()))
B = [(x, i) for i, x in enumerate(a)]
B.sort()
P = [0 for _ in range(n)]
for i in range(n):
    P[B[i][1]] = i
for i in range(n):
    print(P[i], ' ')