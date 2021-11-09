import heapq
import sys
si = sys.stdin.readline
MOD = 1000000009

dy = [[0, 0, 0, 0] for _ in range(100005)]
# 초기값 채우기
dy[1][1] = 1
dy[2][2] = 1
dy[3][1] = 1
dy[3][2] = 1
dy[3][3] = 1

# 점화식을 토대로 dy 배열 채우기
for i in range(4, 100001):
    for cur in range(1, 4):
        for prev in range(1, 4):
            if cur == prev: continue
            dy[i][cur] += dy[i - cur][prev]
            dy[i][cur] %= MOD

T = int(si())
for _ in range(T):
    print(sum(dy[int(si())]) % MOD)
