from collections import deque
n, k=map(int, input().split())
visit=[]
d=[]
for i in range(k):
    d.append([])
for i in range(n):
    visit.append(list(map(int, input().split())))
    for j in range(n):
        if visit[i][j]!=0:
            d[visit[i][j]-1].append([i, j])
q=deque()
s, x, y=map(int, input().split())
for i in range(k):
    for j in d[i]:
        q.append([j[0], j[1], 0])
while q:
    q_pop=q.popleft()
    i=q_pop[0]
    j=q_pop[1]
    cost=q_pop[2]
    if cost==s:
        break
    if i-1>=0 and visit[i-1][j]==0:
        q.append([i-1, j, cost+1])
        visit[i-1][j]=visit[i][j]
    if j-1>=0 and visit[i][j-1]==0:
        q.append([i, j-1, cost+1])
        visit[i][j-1]=visit[i][j]
    if i+1<n and visit[i+1][j]==0:
        q.append([i+1, j, cost+1])
        visit[i+1][j]=visit[i][j]
    if j+1<n and visit[i][j+1]==0:
        q.append([i, j+1, cost+1])
        visit[i][j+1]=visit[i][j]
print(visit[x-1][y-1])
