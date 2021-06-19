import sys
import queue

n = int(sys.stdin.readline().strip())
name = list(sys.stdin.readline().strip().split())
name.sort()
number = dict()
for i in range(n):
	number[name[i]] = i

m = int(sys.stdin.readline().strip())
graph = [[] for i in range(n + 1)]
indeg = [0 for i in range(n + 1)]
for i in range(m):
	x, y = sys.stdin.readline().strip().split()
	graph[number[y]].append(number[x])
	indeg[number[x]] += 1

que = queue.Queue()
parent = []
for i in range(n):
	if indeg[i] == 0:
		que.put(i)
		parent.append(name[i])

child = [[] for i in range(n + 1)]
while que.qsize():
	now = que.get()
	for next in graph[now]:
		indeg[next] -= 1
		if indeg[next] == 0:
			que.put(next)
			child[now].append(next)

print(len(parent))
for x in parent:
	print(x, end = ' ')
print()

for i in range(n):
	print(name[i], len(child[i]), end = ' ')
	child[i].sort()
	for x in child[i]:
		print(name[x], end = ' ')
	print()