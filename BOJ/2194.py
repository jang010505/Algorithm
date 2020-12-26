from collections import deque
n, m, a, b, k=map(int, input().split())
visit=[[0]*(m+1) for i in range(n+1)]
for i in range(k):
    x, y=map(int, input().split())
    visit[x][y]=1
s_x, s_y=map(int, input().split())
e_x, e_y=map(int, input().split())
q=deque()
q.append([s_x, s_y])
d=[[1, 0], [-1, 0], [0, 1], [0, -1]]
visit[s_x][s_y]=1
while q:
    q_pop=q.popleft()
    now_x=q_pop[0]
    now_y=q_pop[1]
    chk=1
    for i in d:
        chk=False
        for j in range(a):
            for k in range(b):
                x=now_x+j+i[0]
                y=now_y+k+i[1]
                if 0<x<=n and 0<y<=m:
                    if visit[x][y]==1:
                        chk=True
                        break
                else:
                    chk=True
                    break
            if chk:
                break
        if chk==False and visit[now_x+i[0]][now_y+i[1]]==0:
            visit[now_x+i[0]][now_y+i[1]]=1+visit[now_x][now_y]
            q.append([now_x+i[0], now_y+i[1]])
print(visit[e_x][e_y]-1)
