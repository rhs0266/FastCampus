import sys
from collections import deque
si = sys.stdin.readline
limit = list(map(int, si().split()))

visit = [[[False] * 205 for _ in range(205)] for _ in range(205)]
possible = [0] * 205

def bfs():
    def move(cur, f, t):
        res = [cur[0], cur[1], cur[2]]
        if cur[f] + cur[t] <= limit[t]:
            res[t] = res[f] + res[t]
            res[f] = 0
        else:
            res[f] -= limit[t] - res[t]
            res[t] = limit[t]
        return res

    queue = deque()
    queue.append([0, 0, limit[2]])
    visit[0][0][limit[2]] = True

    while queue:
        cur = queue.popleft()
        if cur[0] == 0: possible[cur[2]] = True
        for f in range(3):
            for t in range(3):
                if f == t: continue
                nxt = move(cur, f, t)
                if visit[nxt[0]][nxt[1]][nxt[2]]: continue
                visit[nxt[0]][nxt[1]][nxt[2]] = True
                queue.append(nxt)
    

bfs()
for i in range(205):
    if possible[i]:
        print(i, end=' ')