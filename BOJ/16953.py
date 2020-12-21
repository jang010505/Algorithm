from collections import deque
a, b=map(int, input().split())
q=deque()
q.append([a, 1])
cost=1
while q:
    q_pop=q.popleft()
    x=q_pop[0]
    cost=q_pop[1]
    if x==b:
        print(cost)
        exit()
    if x*2<=b:
        q.append([x*2, cost+1])
    if x*10+1<=b:
        q.append([x*10+1, cost+1])
print(-1)
