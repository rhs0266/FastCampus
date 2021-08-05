import heapq
import sys
si = sys.stdin.readline

n = int(si())
m = int(si())
con = [[] for _ in range(n + 1)]
for _ in range(m):
    u, v, weight = map(int, si().split())
    con[u].append((v, weight))
start, destination = map(int, si().split())

# 모든 정점까지에 대한 거리를 무한대로 초기화 해주기.
# ※주의사항※
# 문제의 정답으로 가능한 거리의 최댓값보다 큰 값임을 보장해야 한다.
dist = [1005 * 100000] * (n + 1)
dist[start] = 0

# 최소 힙 생성
Q = []
heapq.heappush(Q, (0, start))

# 거리 정보들이 모두 소진될 때까지 거리 갱신을 반복한다.
while Q:
    dist_x, x = heapq.heappop(Q)

    # 꺼낸 정보가 최신 정보랑 다르면, 의미없이 낡은 정보이므로 폐기한다.
    if dist[x] != dist_x: continue

    # 연결된 모든 간선들을 통해서 다른 정점들에 대한 정보를 갱신해준다.
    for u, weight in con[x]:
        # u 까지 갈 수 있는 더 짧은 거리를 찾았다면 이에 대한 정보를 갱신하고 PQ에 기록해준다.
        if dist[u] > dist[x] + weight:
            dist[u] = dist[x] + weight
            heapq.heappush(Q, (dist[u], u))

print(dist[destination])
