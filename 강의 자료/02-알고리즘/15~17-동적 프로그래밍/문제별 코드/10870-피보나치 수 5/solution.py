import sys
sys.setrecursionlimit(100005)
si = sys.stdin.readline

Q = int(si())
dy = [0] * (Q + 2)

dy[0], dy[1] = 0, 1

for i in range(2, Q + 1):
    dy[i] = dy[i - 1] + dy[i - 2]

print(dy[Q])
