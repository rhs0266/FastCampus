import sys
si = sys.stdin.readline

n, S, M = list(map(int, si().split()))
a = [0] + list(map(int, si().split()))
dy = [[False for __ in range(M + 1)] for _ in range(n + 1)]

# 초기값 구하기
dy[0][S] = True

# 점화식을 토대로 dy 배열 채우기
for i in range(1, n + 1):
    ans = -1
    for prev in range(M + 1):
        if not dy[i - 1][prev]: continue
        for cur in [prev - a[i], prev + a[i]]:
            if cur < 0 or cur > M: continue
            ans = max(ans, cur)
            dy[i][cur] = True

print(ans)
