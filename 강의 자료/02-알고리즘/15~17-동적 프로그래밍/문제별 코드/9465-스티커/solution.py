import sys
si = sys.stdin.readline
TT = int(si())
for _TT in range(TT):
    n = int(si())
    a= [[0, 0] for _ in range(n)]
    for j in range(2):
        b = list(map(int, si().split()))
        for i in range(n):
            a[i][j] = b[i]

    dy = [[0, 0, 0] for _ in range(n)]

    # 초기값 채우기
    dy[0][1], dy[0][2] = a[0][0], a[0][1]

    # 점화식을 토대로 dy 배열 채우기
    for i in range(1, n):
        for prev in range(0, 3):
            dy[i][0] = max(dy[i][0], dy[i - 1][prev])
            for j in range(2):
                if prev & (1 << j): continue
                dy[i][1 << j] = max(dy[i][1 << j], dy[i - 1][prev] + a[i][j])

    print(max(dy[n - 1]))
