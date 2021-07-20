import sys
sys.setrecursionlimit(10**6)

MOD = 1000000007
n = int(input())
bulb = list(map(int, input().split()))
adj = [[] for _ in range(n)]
dp = [[0 for _ in range(10)] for _ in range(n)]
for i in range(n - 1):
    x, y = map(int, input().split())
    adj[x - 1].append(y - 1)
    adj[y - 1].append(x - 1)

def dfs(parent, now):
    nowb = bulb[now]
    dp[now][nowb] = 1
    for nex in adj[now]:
        if nex == parent:
            continue
        dfs(now, nex)
        for i in range(10):
            dp[now][i] = (dp[now][i] + dp[nex][i]) % MOD
        for i in range(nowb, 10):
            dp[now][nowb] = (dp[now][nowb] + dp[nex][i]) % MOD

dfs(-1, 0)
res = 0
for i in range(10):
    res = (res + dp[0][i]) % MOD
print(res)