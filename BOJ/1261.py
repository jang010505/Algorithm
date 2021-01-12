from collections import deque
m, n=map(int, input().split())
list_x=[]
d=[[1, 0], [-1, 0], [0, 1], [0, -1]]
broke=[[0]*m for i in range(n)]
visit=[[0]*m for i in range(n)]
for i in range(n):
    list_x.append(list(input()))
    for j in range(m):
        visit[i][j]=-1
q=deque()
q.append((0, 0))
visit[0][0]=0
while q:
    now_i, now_j=q.popleft()
    for di, dj in d:
        i=now_i+di
        j=now_j+dj
        if 0<=i<n and 0<=j<m:
            if visit[i][j]==-1:
                if list_x[i][j]=='1':
                    visit[i][j]=1+visit[now_i][now_j]
                    q.append((i, j))
                else:
                    visit[i][j]=visit[now_i][now_j]
                    q.appendleft((i, j))
print(visit[n-1][m-1])
