import sys
sys.setrecursionlimit(500005)
si = sys.stdin.readline

# 모든 leaf node 들의 깊이의 합이 짝수냐 홀수냐가 승리 요건
# sum_leaf_depth: 모든 leaf node 들의 깊이의 합
sum_leaf_depth = 0
con = []

def input():
    global con
    n = int(si())
    con = [[] for _ in range(n + 1)]
    for i in range(n - 1):
        x, y = map(int, si().split())
        con[x].append(y)
        con[y].append(x)


def dfs(x, prev, depth):
    global con, sum_leaf_depth
    if x != 1 and len(con[x]) == 1:
        sum_leaf_depth += depth
    for y in con[x]:
        if y == prev: continue
        dfs(y, x, depth + 1)


def pro():
    dfs(1, -1, 0)
    print("Yes" if sum_leaf_depth % 2 == 1 else "No")


if __name__ == "__main__":
    input()
    pro()