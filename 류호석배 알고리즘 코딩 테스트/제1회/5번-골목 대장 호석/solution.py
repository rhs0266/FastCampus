import heapq
import sys

# Dijkstra
def dijkstra(max_cash):
    pq = []
    for i in range(n):
        dist[i] = -1
    dist[a] = 0
    heapq.heappush(pq, (0, a))

    while pq:
        now_node = heapq.heappop(pq)
        if dist[now_node[1]] != now_node[0]:
            continue
        for next_node in graph[now_node[1]]:
            if next_node[1] <= max_cash and (dist[next_node[0]] == -1 or dist[next_node[0]] > now_node[0] + next_node[1]):
                dist[next_node[0]] = now_node[0] + next_node[1]
                heapq.heappush(pq, (dist[next_node[0]], next_node[0]))
    return dist[b] != -1 and dist[b] <= c


# Input
line = sys.stdin.readline().rstrip().split(' ')
n = int(line[0])
m = int(line[1])
a = int(line[2])
b = int(line[3])
c = int(line[4])

a -= 1
b -= 1
graph = [[] for _ in range(n)]
dist = [0] * n
for i in range(m):
    line = sys.stdin.readline().rstrip().split(' ')
    x = int(line[0])
    y = int(line[1])
    cash = int(line[2])
    x -= 1
    y -= 1
    graph[x].append((y, cash))
    graph[y].append((x, cash))

# Parametric Search
start = 0
end = 1000000007
answer = -1
while start < end:
    mid = (start + end) // 2
    if dijkstra(mid):
        answer = end = mid
    elif start == mid:
        break
    else:
        start = mid

# Print
print(answer)
