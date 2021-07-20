import heapq
import sys
q = int(sys.stdin.readline())
gorilla = dict()
heap = []
result = 0

for i in range(q):
    now = sys.stdin.readline().split()
    name = now[1]
    if now[0] == "1":
        idx = len(gorilla)
        if name in gorilla:
            idx = gorilla[name]
        else:
            gorilla[name] = idx
            heap.append([])
        for i in range(3, int(now[2]) + 3):
            heapq.heappush(heap[idx], int(now[i]) * -1)
    else:
        idx = len(gorilla)
        if name in gorilla:
            idx = gorilla[name]
        else:
            continue
        for i in range(int(now[2])):
            if heap[idx]:
                result -= heapq.heappop(heap[idx])
print(result)