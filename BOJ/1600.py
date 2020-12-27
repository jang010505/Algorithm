from collections import deque
k=int(input())
m, n=map(int, input().split())
list_x=[]
d_1=[[2, 1], [2, -1], [-2, 1], [-2, -1], [1, 2], [1, -2], [-1, 2], [-1, -2]]
d_2=[[1, 0], [0, 1], [-1, 0], [0, -1]]
visit=[]
for i in range(k+1):
    visit.append([[0]*m for j in range(n)])
for i in range(n):
    list_x.append(list(map(int, input().split())))
q=deque()
q.append([0, 0, 0])
visit[0][0][0]=1
while q:
    q_pop=q.popleft()
    now_i=q_pop[0]
    now_j=q_pop[1]
    cost=q_pop[2]
    if now_i==n-1 and now_j==m-1:
        break
    if cost<k:
        for x in d_1:
            i=now_i+x[0]
            j=now_j+x[1]
            if 0<=i<n and 0<=j<m:
                if list_x[i][j]==0 and visit[cost+1][i][j]==0:
                    q.append([i, j, cost+1])
                    visit[cost+1][i][j]=visit[cost][now_i][now_j]+1
    for x in d_2:
        i=now_i+x[0]
        j=now_j+x[1]
        if 0<=i<n and 0<=j<m:
            if list_x[i][j]==0 and visit[cost][i][j]==0:
                q.append([i, j, cost])
                visit[cost][i][j]=1+visit[cost][now_i][now_j]
print(visit[cost][n-1][m-1]-1)
