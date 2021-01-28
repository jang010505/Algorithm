from collections import deque
d=[[1, 0], [-1, 0], [0, 1], [0, -1]]
n, m=map(int, input().split())
dq=deque()
info=list()
fire_visit=[[1000000]*m for i in range(n)]
for i in range(n):
    info.append(list(input()))
    for j in range(m):
        if info[i][j]=='F':
            fire_visit[i][j]=1
            dq.append((i, j))
        elif info[i][j]=='J':
            start_i=i
            start_j=j
while dq:
    now_i, now_j=dq.popleft()
    for di, dj in d:
        nxt_i=now_i+di
        nxt_j=now_j+dj
        if 0<=nxt_i<n and 0<=nxt_j<m:
            if fire_visit[nxt_i][nxt_j]==1000000 and info[nxt_i][nxt_j]!='#':
                fire_visit[nxt_i][nxt_j]=fire_visit[now_i][now_j]+1
                dq.append((nxt_i, nxt_j))
dq.clear()
dq.append((start_i, start_j))
visit=[[0]*m for i in range(n)]
visit[start_i][start_j]=1
chk=True
while dq:
    now_i, now_j=dq.popleft()
    if now_i==0 or now_j==0 or now_i==n-1 or now_j==m-1:
        print(visit[now_i][now_j])
        chk=False
        break
    for di, dj in d:
        nxt_i=now_i+di
        nxt_j=now_j+dj
        if 0<=nxt_i<n and 0<=nxt_j<m:
            if visit[nxt_i][nxt_j]==0 and visit[now_i][now_j]+1<fire_visit[nxt_i][nxt_j] and info[nxt_i][nxt_j]!='#':
                visit[nxt_i][nxt_j]=visit[now_i][now_j]+1
                dq.append((nxt_i, nxt_j))
if chk:
    print("IMPOSSIBLE")
