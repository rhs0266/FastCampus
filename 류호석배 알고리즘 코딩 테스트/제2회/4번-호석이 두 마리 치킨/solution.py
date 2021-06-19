import sys
n, m = map(int, sys.stdin.readline().strip().split())
adj = [[101 for j in range(n)] for i in range(n)]

for i in range(m):
	a, b = map(int, sys.stdin.readline().strip().split())
	adj[a - 1][b - 1] = 1
	adj[b - 1][a - 1] = 1

for i in range(n):
	adj[i][i] = 0

for k in range(n):
	for i in range(n):
		if i == k:
			continue
		for j in range(n):
			if i == j or j == k:
				continue
			if adj[i][j] > adj[i][k] + adj[k][j]:
				adj[i][j] = adj[i][k] + adj[k][j]


building = [1, 2]
res = 101010
for i in range(n):
	for j in range(i + 1, n):
		now = 0
		for k in range(n):
			if i == k or j == k:
				continue
			now += min(adj[i][k], adj[j][k])
		if res > now:
			building = [i + 1, j + 1]
			res = now

print(building[0], building[1], res * 2)