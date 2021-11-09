import sys
si = sys.stdin.readline

n = int(si())
dy = [[[[0 for _4 in range(10)] for _3 in range(10)] for _2 in range(10)] for _1 in range(n + 1)]
MOD = 1000000000

# 초기값 구하기
for num in range(1, 10):
    dy[1][num][num][num] = 1

# 점화식을 토대로 dy 배열 채우기
for len in range(2, n + 1):
    for prev in range(10):
        for low in range(10):
            for high in range(10):
                for cur in [prev - 1, prev + 1]:
                    if cur < 0 or cur > 9: continue
                    dy[len][cur][min(low, cur)][max(high, cur)] += dy[len - 1][prev][low][high]
                    dy[len][cur][min(low, cur)][max(high, cur)] %= MOD

ans = 0
for i in range(10):
    ans += dy[n][i][0][9]
    ans %= MOD

print(ans)