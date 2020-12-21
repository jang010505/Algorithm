from collections import deque
n, m=map(int, input().split())
x=[]
q=deque()
for i in range(n):
    x.append(list(map(int, input().split())))
    for j in range(m):
        if x[i][j]==1:
            q.append([i, j, 0])
res=[]
while q:
    q_pop=q.popleft()
    i=q_pop[0]
    j=q_pop[1]
    cost=q_pop[2]
    if i-1>=0 and j-1>=0:
        if x[i-1][j-1]==1:
            res.append(cost)
        else:
            q.append([i-1, j-1, cost+1])
            x[i-1][j-1]=1
    if i-1>=0:
        if x[i-1][j]==1:
            res.append(cost)
        else:
            q.append([i-1, j, cost+1])
            x[i-1][j]=1
    if i-1>=0 and j+1<m:
        if x[i-1][j+1]==1:
            res.append(cost)
        else:
            q.append([i-1, j+1, cost+1])
            x[i-1][j+1]=1
    if j-1>=0:
        if x[i][j-1]==1:
            res.append(cost)
        else:
            q.append([i, j-1, cost+1])
            x[i][j-1]=1
    if j+1<m:
        if x[i][j+1]==1:
            res.append(cost)
        else:
            q.append([i, j+1, cost+1])
            x[i][j+1]=1
    if i+1<n and j-1>=0:
        if x[i+1][j-1]==1:
            res.append(cost)
        else:
            q.append([i+1, j-1, cost+1])
            x[i+1][j-1]=1
    if i+1<n:
        if x[i+1][j]==1:
            res.append(cost)
        else:
            q.append([i+1, j, cost+1])
            x[i+1][j]=1
    if i+1<n and j+1<m:
        if x[i+1][j+1]==1:
            res.append(cost)
        else:
            q.append([i+1, j+1, cost+1])
            x[i+1][j+1]=1
print(max(res))
