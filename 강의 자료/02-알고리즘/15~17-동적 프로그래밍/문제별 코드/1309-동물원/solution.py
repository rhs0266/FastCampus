import sys
si = sys.stdin.readline
MOD = 9901

n = int(si())

dy = [[0, 0, 0] for _ in range(n)]

# 초기값 채우기
dy[0][0], dy[0][1], dy[0][2] = 1, 1, 1

# 점화식을 토대로 dy 배열 채우기
for i in range(1, n):
    for prev in range(0, 3):
        dy[i][0] += dy[i - 1][prev]
        dy[i][0] %= MOD
        for j in range(2):
            if prev & (1 << j): continue
            dy[i][1 << j] += dy[i - 1][prev]
            dy[i][1 << j] %= MOD

print(sum(dy[n - 1]) % MOD)
