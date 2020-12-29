from collections import deque
n, m, v=map(int, input().split())
x, y=map(int, input().split())
list_x=[]
list_y=[]
d=[[1, 0], [-1, 0], [0, 1], [0, -1]]
visit_time=[[10000]*m for i in range(n)]
q_vol=deque()
for _ in range(n):
    list_x.append(list(map(int, input().split())))
for _ in range(v):
    a, b, t=map(int, input().split())
    visit=[[0]*m for i in range(n)]
    visit_time[a-1][b-1]=0
    q_vol.append((a-1, b-1))
    t+=1
    while q_vol:
        for I in range(len(q_vol)):
            now_i, now_j=q_vol.popleft()
            for k in d:
                i=now_i+k[0]
                j=now_j+k[1]
                if 0<=i<n and 0<=j<m:
                    if visit[i][j]==0:
                        visit[i][j]=1
                        visit_time[i][j]=min(visit_time[i][j], t)
                        q_vol.append((i, j))
        t+=1
q_js=deque()
q_js.append([x-1, y-1])
visit=[[0]*m for i in range(n)]
visit[x-1][y-1]=1
max_h=list_x[x-1][y-1]
max_cnt=0
while q_js:
    now_i, now_j=q_js.popleft()
    for k in d:
        i=now_i+k[0]
        j=now_j+k[1]
        if 0<=i<n and 0<=j<m:
            if visit[i][j]==0:
                visit[i][j]=1+visit[now_i][now_j]
                if visit[i][j]-1<visit_time[i][j]:
                    q_js.append([i, j])
                    if max_h<list_x[i][j]:
                        max_h=list_x[i][j]
                        max_cnt=visit[i][j]-1
                    if max_h==list_x[i][j]:
                        mac_cnt=min(visit[i][j]-1, max_cnt)
print(max_h, max_cnt)
