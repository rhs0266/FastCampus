import sys
sys.setrecursionlimit(100005)
si = sys.stdin.readline

Q = int(si())
dy = [[0, 0] for _ in range(Q + 1)]

# dy[i][k] := i자리 이친수 중에서 마지막 숫자가 j 인 경우의 수
dy[1][1] = 1
for i in range(2, Q + 1):
    dy[i][0] = dy[i - 1][0] + dy[i - 1][1]
    dy[i][1] = dy[i - 1][0]

print(sum(dy[Q]))