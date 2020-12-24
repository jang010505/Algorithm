from collections import deque
n=int(input())
a, b=map(int, input().split())
m=int(input())
d=[]
for i in range(n):
    d.append([])
for i in range(m):
    x, y=map(int, input().split())
    d[x-1].append(y-1)
    d[y-1].append(x-1)
q=deque()
chk=1
q.append([a-1, 0])
visit=[0]*n
while q:
    q_pop=q.popleft()
    now=q_pop[0]
    cost=q_pop[1]
    visit[now]=1
    if now==b-1:
        chk=0
        break
    for i in d[now]:
        if visit[i]==0:
            q.append([i, cost+1])
if chk: print(-1)
else: print(cost)
