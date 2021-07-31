import sys
si = sys.stdin.readline

while True:
    n, K = map(int, si().split())
    if n == 0 and K == 0: break
    a = [0] + list(map(int, si().split()))
    
    # 각 노드의 부모 노드 인덱스를 계산하자. 루트 노드가 1번 노드임을 주의하라.
	# 편의상 0번 정점의 부모를 -1 로 하자.
    par = [0] * (n + 1)
    par[0] = -1
    
    # last := 이번에 자식 정점들을 찾을 노드의 인덱스
    last = 1
    # i := 이번에 부모 정점을 찾을 노드의 인덱스
    i = 2
    while i <= n:
        while i <= n:  # i번부터 연속한 수를 가진 정점을 모두 last 의 자식으로 묶는다.
            par[i] = last
            if i < n and a[i] + 1 != a[i + 1]:
                break
            i += 1
        i += 1
        last += 1
    
    kIdx = 0  # 수가 K인 정점의 인덱스
    for i in range(1, n + 1):
        if a[i] == K:
            kIdx = i

    ans = 0
    for i in range(1, n + 1):
        # 사촌 := 부모의 부모는 동일하나 부모는 다른 정점의 개수
        if par[par[i]] == par[par[kIdx]] and par[i] != par[kIdx]:
            ans += 1
    
    print(ans)
