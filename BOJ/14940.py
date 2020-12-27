from collections import deque
n, m=map(int, input().split())
visit=[[0]*m for i in range(n)]
list_x=[]
d=[[1, 0], [-1, 0], [0, 1], [0, -1]]
for i in range(n):
    list_x.append(list(map(int, input().split())))
    for j in range(m):
        if list_x[i][j]==2:
            start_i, start_j=i, j
visit[start_i][start_j]=2
q=deque()
q.append([start_i, start_j])
while q:
    q_pop=q.popleft()
    now_i=q_pop[0]
    now_j=q_pop[1]
    for k in d:
        if 0<=now_i+k[0]<n and 0<=now_j+k[1]<m:
            if list_x[now_i+k[0]][now_j+k[1]]==1 and visit[now_i+k[0]][now_j+k[1]]==0:
                visit[now_i+k[0]][now_j+k[1]]=1+visit[now_i][now_j]
                q.append([now_i+k[0], now_j+k[1]])
for i in range(n):
    for j in range(m):
        if visit[i][j]==0 and list_x[i][j]==1:
            print(-1, end=' ')
        elif list_x[i][j]==0:
            print(0, end=' ')
        else:
            print(visit[i][j]-2, end=' ')
    print()
