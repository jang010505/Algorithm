from collections import deque
f, s, g, u, d=map(int, input().split())
visit=[0]*(f+1)
visit[s]=1
q=deque()
q.append([s, 0])
while q:
    q_pop=q.popleft()
    now=q_pop[0]
    cost=q_pop[1]
    if now+u<=f and visit[now+u]==0:
        q.append([now+u, cost+1])
        visit[now+u]=visit[now]+1
    if now-d>0 and visit[now-d]==0:
        q.append([now-d, cost+1])
        visit[now-d]=visit[now]+1
if visit[g]:  print(visit[g]-1)
else: print("use the stairs")
