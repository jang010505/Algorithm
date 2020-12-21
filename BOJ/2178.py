import sys
from collections import deque
n, m=map(int, input().split())
x, q=[], deque()
for i in range(n):
    x.append(list(sys.stdin.readline()))
cost=-1
q.append([0, 0, 1])
while q:
    q_pop=q.popleft()
    i=q_pop[0]
    j=q_pop[1]
    cost=q_pop[2]
    if i==n-1 and j==m-1: break
    if i-1>=0 and x[i-1][j]=='1':
        q.append([i-1, j, cost+1])
        x[i-1][j]='0'
    if j-1>=0 and x[i][j-1]=='1':
        q.append([i, j-1, cost+1])
        x[i][j-1]='0'
    if i+1<n and x[i+1][j]=='1':
        q.append([i+1, j, cost+1])
        x[i+1][j]='0'
    if j+1<m and x[i][j+1]=='1':
        q.append([i, j+1, cost+1])
        x[i][j+1]='0'
print(cost)
