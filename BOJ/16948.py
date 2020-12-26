from collections import deque
x=[[-2, -1], [-2, 1], [0, -2], [0, 2], [2, -1], [2, 1]]
n=int(input())
r1, c1, r2, c2=map(int, input().split())
visit=[[0]*n for i in range(n)]
q=deque()
q.append([r1, c1, 0])
visit[r1][c1]=1
chk=1
while q:
    q_pop=q.popleft()
    i=q_pop[0]
    j=q_pop[1]
    cost=q_pop[2]
    if i==r2 and j==c2:
        chk=0
        break
    for k in x:
        if 0<=i+k[0]<n and 0<=j+k[1]<n and visit[i+k[0]][j+k[1]]==0:
            q.append([i+k[0], j+k[1], cost+1])
            visit[i+k[0]][j+k[1]]=1
if chk: print(-1)
else: print(cost)
