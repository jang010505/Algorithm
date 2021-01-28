from collections import deque
w, h=map(int, input().split())
info=list()
R=list()
d=[[1, 0], [-1, 0], [0, 1], [0, -1]]
for i in range(h):
    info.append(list(input()))
    for j in range(w):
        if info[i][j]=='C':
            R.append((i, j))
start_i, start_j=R[0]
end_i, end_j=R[1]
visit=[[10000]*w for i in range(h)]
dq=deque()
dq.append((start_i, start_j, 0, 0))
visit[start_i][start_j]=0
while dq:
    now_i, now_j, DI, DJ=dq.popleft()
    if DI!=DJ and 0<=now_i+DI<h and 0<=now_j+DJ<w and visit[now_i+DI][now_j+DJ]>=visit[now_i][now_j] and info[now_i+DI][now_j+DJ]!='*':
        visit[now_i+DI][now_j+DJ]=visit[now_i][now_j]
        dq.append((now_i+DI, now_j+DJ, DI, DJ))
    for di, dj in d:
        nxt_i=now_i+di
        nxt_j=now_j+dj
        if di==DI and dj==DJ:
            continue
        if 0<=nxt_i<h and 0<=nxt_j<w:
            if visit[nxt_i][nxt_j]>=visit[now_i][now_j]+1 and info[nxt_i][nxt_j]!='*':
                visit[nxt_i][nxt_j]=visit[now_i][now_j]+1
                dq.append((nxt_i, nxt_j, di, dj))
print(visit[end_i][end_j]-1)
