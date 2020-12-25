from collections import deque
a, b=map(int, input().split())
n, m=map(int, input().split())
visit=[0]*(n+1)
d=[[] for i in range(n+1)]
for i in range(m):
    x, y=map(int, input().split())
    d[x].append(y)
    d[y].append(x)
q=deque()
q.append([a, 0])
chk=1
visit[a]=1
while q:
    q_pop=q.popleft()
    now=q_pop[0]
    cost=q_pop[1]
    if now==b:
        chk=0
        break
    for i in d[now]:
        if visit[i]==0:
            q.append([i, cost+1])
            visit[i]=1
if chk: print(-1)
else: print(cost)
