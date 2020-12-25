from collections import deque
a, b, n, m=map(int, input().split())
visit=[0]*100001
q=deque()
q.append([n, 0])
visit[n]=1
while q:
    q_pop=q.popleft()
    now=q_pop[0]
    cost=q_pop[1]
    if now==m:
        break
    if now-1>=0 and visit[now-1]==0:
        q.append([now-1, cost+1])
        visit[now-1]=1
    if now+1<=100000 and visit[now+1]==0:
        q.append([now+1, cost+1])
        visit[now+1]=1
    if now-a>=0 and visit[now-a]==0:
        q.append([now-a, cost+1])
        visit[now-a]=1
    if now+a<=100000 and visit[now+a]==0:
        q.append([now+a, cost+1])
        visit[now+a]=1
    if now-b>=0 and visit[now-b]==0:
        q.append([now-b, cost+1])
        visit[now-b]=1
    if now+b<=100000 and visit[now+b]==0:
        q.append([now+b, cost+1])
        visit[now+b]=1
    if now*a<=100000 and visit[now*a]==0:
        q.append([now*a, cost+1])
        visit[now*a]=1
    if now*b<=100000 and visit[now*b]==0:
        q.append([now*b, cost+1])
        visit[now*b]=1
print(cost)
