# 세 가지 풀이가 가능하다.
# 1. 트리도 일종의 그래프이므로 최단거리 알고리즘인 Dijkstra 사용
# 2. 트리에서 두 노드 사이의 경로는 유일한 점을 활용해서 BFS 사용
# 3. 트리를 Rooted 트리로 변환해서 구현이 짧은 DFS를 통해 거리 계산하기.
#    마찬가지로 두 노드 사이의 경로가 유일함을 확인한다.
# 본 풀이는 3 번 접근을 다룬다.
    
import sys
si = sys.stdin.readline

n, m = map(int, si().split())
con = [[] for _ in range(n + 1)]
for i in range(n - 1):
    x, y, c = map(int, si().split())
    con[x].append((y, c))
    con[y].append((x, c))

# 현재 x 에 있으며, 부모 노드는 prev 이며, 목표 지점은 goal,
# 그리고 root부터 지금까지 이동 거리가 dist 이다.
def DFS(x, prev, goal, dist):
    if x == goal:
        print(dist)
        return
    for y, c in con[x]:
        if y == prev:
            continue
        DFS(y, x, goal, dist + c)

for _ in range(m):
    x, y = map(int, si().split())
    DFS(x, -1, y, 0)
