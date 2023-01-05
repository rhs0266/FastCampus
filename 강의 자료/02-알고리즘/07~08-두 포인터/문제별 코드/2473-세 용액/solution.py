import sys
input = sys.stdin.readline
n = int(input())
arr = sorted(list(map(int, input().split())))

best_val = float("inf") # 최소값 찾는 문제니까 초기값은 최대값
ans = []
for i in range(n - 2):
    left, right = i + 1, n - 1

    while left < right:
        sum_val = arr[i] + arr[left] + arr[right]

        if abs(best_val) > abs(sum_val): # 기존 합보다 새로운 세 수의 합이 작으면 갱신
            best_val = sum_val
            ans = [arr[i], arr[left], arr[right]]
        
        if sum_val > 0: # 세 수의 합이 양수면 더 작게 만들기
            right -= 1
        elif sum_val < 0: # 세 수의 합이 음수면 더 크게 만들기
            left += 1
        else: # 합이 0이면 바로 끝내기
            i = n
            break

for a in sorted(ans):
    print(a, end=" ")