import sys
from heapq import heappop, heappush

V, E = map(int, sys.stdin.readline().split())

K = int(sys.stdin.readline())

nod_lst = [[] for i in range (V+1)]

for i in range (E) :
    u, v, w = map(int, sys.stdin.readline().split())
    nod_lst[u].append((w, v))
    
# 이동 초기화 최대치 설정
maximum = 1000000000000

# 이동 시간 저장 리스트
cost_lst = [maximum] * (V+1)
cost_lst[K] = 0

# 실행을 위한 우선순위 큐
lst = []
lst.append((0, K))

def Dijkstra() :
    while lst:
        where = heappop(lst)
        now = where[1]
        expence = where[0]
        if cost_lst[now] < expence :
            continue
        for cost, nxt in nod_lst[now] :
            nxt_cost = cost + expence
            if nxt_cost < cost_lst[nxt] :
                cost_lst[nxt] = nxt_cost
                heappush(lst, (nxt_cost, nxt))

Dijkstra()

for i in range (1, V+1) :
    if cost_lst[i] != maximum :
        print(cost_lst[i])
    else :
        print("INF")
