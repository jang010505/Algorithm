from collections import deque
n, m=map(int, input().split())
list_x=[]
d=[[1, 0], [-1, 0], [0, 1], [0, -1]]
for i in range(n):
    list_x.append(list(input()))
q=deque()
q.append((0, 0, 1))
visit=[]
for i in range(n):
    visit.append([])
    for j in range(m):
        visit[i].append([])
        visit[i][j].append(0)
        visit[i][j].append(0)
visit[0][0][1]=1
while q:
    now_i, now_j, brk=q.popleft()
    if now_i==n-1 and now_j==m-1:
        break
    for k in d:
        i=now_i+k[0]
        j=now_j+k[1]
        if 0<=i<n and 0<=j<m:
            if list_x[i][j]=='1' and brk:
                visit[i][j][brk-1]=1+visit[now_i][now_j][brk]
                q.append((i, j, brk-1))
            if list_x[i][j]=='0' and visit[i][j][brk]==0:
                visit[i][j][brk]=1+visit[now_i][now_j][brk]
                q.append((i, j, brk))
if visit[n-1][m-1][brk]: print(visit[n-1][m-1][brk])
else: print(-1)
