from collections import deque
n=int(input())
visit=[[0]*1001 for i in range(1001)]
visit[1][0]=1
q=deque()
q.append([1, 0, 0])
while q:
    q_pop=q.popleft()
    screen=q_pop[0]
    clip=q_pop[1]
    cost=q_pop[2]
    if screen==n:
        break
    if screen+clip<=1000 and visit[screen+clip][clip]==0:
        q.append([screen+clip, clip, cost+1])
        visit[screen+clip][clip]=1
    if 0<=screen-1 and visit[screen-1][clip]==0:
        q.append([screen-1, clip, cost+1])
        visit[screen-1][clip]=1
    if screen<=1000 and visit[screen][screen]==0:
        q.append([screen, screen, cost+1])
        visit[screen][screen]=1
print(cost)
