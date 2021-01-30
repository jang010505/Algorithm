from collections import deque
n, m=map(int, input().split())
start_i, start_j=map(int, input().split())
end_i, end_j=map(int, input().split())
info=list()
visit=list()
for i in range(2):
    visit.append([[0]*m for j in range(n)])
d=[[1, 0], [-1, 0], [0, 1], [0, -1]]
for i in range(n):
    info.append(list(map(int, input().split())))
dq=deque()
dq.append((start_i-1, start_j-1, 1))
visit[1][start_i-1][start_j-1]=1
while dq:
    now_i, now_j, brk=dq.popleft()
    if now_i==end_i-1 and now_j==end_j-1:
        break
    for di, dj in d:
        nxt_i=now_i+di
        nxt_j=now_j+dj
        if 0<=nxt_i<n and 0<=nxt_j<m:
            if info[nxt_i][nxt_j] and brk:
                visit[brk-1][nxt_i][nxt_j]=visit[brk][now_i][now_j]+1
                dq.append((nxt_i, nxt_j, brk-1))
            if info[nxt_i][nxt_j]==0 and visit[brk][nxt_i][nxt_j]==0:
                visit[brk][nxt_i][nxt_j]=visit[brk][now_i][now_j]+1
                dq.append((nxt_i, nxt_j, brk))
if visit[brk][end_i-1][end_j-1]==0:
    print(-1)
else:
    print(visit[brk][end_i-1][end_j-1]-1)
