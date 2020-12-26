from collections import deque
r, c=map(int, input().split())
visit=[]
water_queue=deque()
q=deque()
d=[[1, 0], [-1, 0], [0, 1], [0, -1]]
cnt=0
for i in range(r):
    visit.append(list(input()))
    for j in range(c):
        if visit[i][j]=='S':
            start_x, start_y=i, j
        if visit[i][j]=='D':
            end_x, end_y=i, j
        if visit[i][j]=='*':
            water_queue.append([i, j])
            cnt+=1
q.append([start_x, start_y, 0])
chk=0
visit_cnt=[[0]*c for i in range(r)]
visit_cnt[start_x][start_y]=1
visit[start_x][start_y]='S'
z=1
temp=1
while q:
    q_pop=q.popleft()
    now_i=q_pop[0]
    now_j=q_pop[1]
    cost=q_pop[2]
    tmp=cnt
    if water_queue and cost==temp:
        temp+=1
        cnt=0
        for i in range(tmp):
            q_pop=water_queue.popleft()
            water_i=q_pop[0]
            water_j=q_pop[1]
            for j in d:
                if 0<=water_i+j[0]<r and 0<=water_j+j[1]<c and (visit[water_i+j[0]][water_j+j[1]]=='.' or visit[water_i+j[0]][water_j+j[1]]=='S'):
                    water_queue.append([water_i+j[0], water_j+j[1]])
                    visit[water_i+j[0]][water_j+j[1]]='*'
                    cnt+=1
    if visit[now_i][now_j]=='*': continue
    for i in d:
        if 0<=now_i+i[0]<r and 0<=now_j+i[1]<c and (visit[now_i+i[0]][now_j+i[1]]=='.' or visit[now_i+i[0]][now_j+i[1]]=='D'):
            q.append([now_i+i[0], now_j+i[1], cost+1])
            visit[now_i+i[0]][now_j+i[1]]='S'
            visit_cnt[now_i+i[0]][now_j+i[1]]=1+visit_cnt[now_i][now_j]
if visit_cnt[end_x][end_y]: print(visit_cnt[end_x][end_y]-1)
else: print("KAKTUS")
