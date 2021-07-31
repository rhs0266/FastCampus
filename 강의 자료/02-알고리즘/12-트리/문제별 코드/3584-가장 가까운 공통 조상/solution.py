import sys
si = sys.stdin.readline


def solve():
    n = int(si())
    par = [0] * (n + 1)
    for _ in range(n - 1):
        u, v = map(int, si().split())
        par[v] = u

    check = [0] * (n + 1)
    x, y = map(int, si().split())

    # x 에서 루트까지 체크를 해놓는다.
    while x:
        check[x] = 1
        x = par[x]
    
    
    # y 에서 루트로 이동하면서 처음으로 만나는 체크된 정점을 찾는다.
    while y and check[y] == 0:
        y = par[y]
    print(y)


T = int(si())
for _ in range(T):
    solve()
