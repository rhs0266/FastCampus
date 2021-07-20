import heapq

n, x = map(int, input().split())
time = list(map(int, input().split()))

start = 1
end = n
while start <= end:
    mid = (start + end) // 2
    flag = True
    heap = [0] * mid
    for t in time:
        now = heapq.heappop(heap)
        if now + t > x:
            flag = False
            break
        heapq.heappush(heap, now + t)   
    if flag:
        end = mid - 1
    else:
        start = mid + 1

print(start)