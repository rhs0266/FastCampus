import sys
sys.setrecursionlimit(100005)
si = sys.stdin.readline

Q = int(si())
dy = [[0, 0] for _ in range(50)]

# dy[][] 를 미리 계산해 놓기
def preprocess():
    # dy[i][k] := fibonacci(i) 를 호출했을 때, k 가 출력되는 횟수
    dy[0][0], dy[1][1] = 1, 1
    for i in range(2, 41):
        dy[i][0] = dy[i - 1][0] + dy[i - 2][0]
        dy[i][1] = dy[i - 1][1] + dy[i - 2][1]

preprocess()

for _ in range(Q):
    x = int(si())
    print(dy[x][0], dy[x][1])