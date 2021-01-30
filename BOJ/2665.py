from collections import deque
n=int(input())
info=list()
d=[[1, 0], [-1, 0], [0, 1], [0, -1]]
visit=[[0]*n for i in range(n)]
for i in range(n):
    info.append(list(input()))
q=deque()
q.append((0, 0))
visit[0][0]=1
while q:
    now_i, now_j=q.popleft()
    for di, dj in d:
        nxt_i=now_i+di
        nxt_j=now_j+dj
        if 0<=nxt_i<n and 0<=nxt_j<n:
            if visit[nxt_i][nxt_j]==0:
                if info[nxt_i][nxt_j]=='0':
                    visit[nxt_i][nxt_j]=1+visit[now_i][now_j]
                    q.append((nxt_i, nxt_j))
                else:
                    visit[nxt_i][nxt_j]=visit[now_i][now_j]
                    q.appendleft((nxt_i, nxt_j))
print(visit[n-1][n-1]-1)
