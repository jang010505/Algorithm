import sys
from collections import deque
m, n, h=map(int, input().split())
x, q=[], deque()
for i in range(h):
    x.append([])
    for j in range(n):
        x[i].append(list(map(int, sys.stdin.readline().split())))
        for k in range(m):
            if x[i][j][k]==1:
                q.append([i, j, k])
cost=-1
while q:
    cost+=1
    for _ in range(len(q)): 
        q_pop=q.popleft()
        i=q_pop[0]
        j=q_pop[1]
        k=q_pop[2]
        if i-1>=0 and x[i-1][j][k]==0:
            q.append([i-1, j, k])
            x[i-1][j][k]=1
        if j-1>=0 and x[i][j-1][k]==0:
            q.append([i, j-1, k])
            x[i][j-1][k]=1
        if k-1>=0 and x[i][j][k-1]==0:
            q.append([i, j, k-1])
            x[i][j][k-1]=1
        if i+1<h and x[i+1][j][k]==0:
            q.append([i+1, j, k])
            x[i+1][j][k]=1
        if j+1<n and x[i][j+1][k]==0:
            q.append([i, j+1, k])
            x[i][j+1][k]=1
        if k+1<m and x[i][j][k+1]==0:
            q.append([i, j, k+1])
            x[i][j][k+1]=1
chk=True
for i in range(h):
    for j in x[i]:
        if 0 in j:
            chk=False
            break
if chk: print(cost)
else: print(-1)
