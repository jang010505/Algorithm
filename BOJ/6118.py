from collections import deque
n, m=map(int, input().split())
d=[[] for i in range(n+1)]
for i in range(m):
    x, y=map(int, input().split())
    d[x].append(y)
    d[y].append(x)
q=deque()
q.append([1, 0])
visit=[0]*(n+1)
for i in range(1, n+1):
    d[i].sort()
visit[1]=1
Cost=0
res=1
index=10000
while q:
    q_pop=q.popleft()
    now=q_pop[0]
    cost=q_pop[1]
    if Cost==cost:
        if index>now: index=now
        res+=1
    if Cost<cost:
        index=now
        Cost=cost
        res=1
    for i in d[now]:
        if visit[i]==0:
            q.append([i, cost+1])
            visit[i]=1
print(index, cost, res)
