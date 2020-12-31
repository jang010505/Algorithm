from collections import deque
n, m, k=map(int, input().split())
list_x=[]
d=[[1, 0], [-1, 0], [0, 1], [0, -1]]
for i in range(n):
    list_x.append(list(input()))
q=deque()
q.append((0, 0, 0))
visit=[[[0]*(k+1) for j in range(m)] for i in range(n)]
visit[0][0][0]=1
while q:
    now_i, now_j, brk=q.popleft()
    if now_i==n-1 and now_j==m-1:
        break
    for v in d:
        i=now_i+v[0]
        j=now_j+v[1]
        if 0<=i<n and 0<=j<m:
            if list_x[i][j]=='1' and brk<k and visit[i][j][brk+1]==0:
                visit[i][j][brk+1]=1+visit[now_i][now_j][brk]
                q.append((i, j, brk+1))
            if list_x[i][j]=='0' and visit[i][j][brk]==0:
                visit[i][j][brk]=1+visit[now_i][now_j][brk]
                q.append((i, j, brk))
if visit[n-1][m-1][brk]: print(visit[n-1][m-1][brk])
else: print(-1)
