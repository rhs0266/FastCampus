import sys
from collections import deque
si = sys.stdin.readline
N, K = list(map(int, si().split()))
X = 100000

dist = [-1] * (X + 1)

def bfs(x):
    queue = deque()
    queue.append(x)
    dist[x] = 0
    def move(y, d):
        if y < 0 or y > X or dist[y] != -1:
            return
        dist[y] = d
        queue.append(y)

    while queue:
        x = queue.popleft()
        move(x - 1, dist[x] + 1)
        move(x + 1, dist[x] + 1)
        move(x * 2, dist[x] + 1)

bfs(N)
print(dist[K])