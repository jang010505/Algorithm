from collections import deque
l, r, c=map(int, input().split())
d=[[1, 0, 0], [-1, 0, 0], [0, 1, 0], [0, -1, 0], [0, 0, 1], [0, 0, -1]]
while l!=0 or r!=0 or c!=0:
    list_x=[]
    visit=[]
    for i in range(l):
        list_x.append([])
        visit.append([[0]*c for j in range(r)])
        for j in range(r):
            list_x[i].append(list(input()))
            for k in range(c):
                if list_x[i][j][k]=='S':
                    start_i, start_j, start_k=i, j, k
                if list_x[i][j][k]=='E':
                    end_i, end_j, end_k=i, j, k
        trash=input()
    q=deque()
    q.append([start_i, start_j, start_k])
    visit[start_i][start_j][start_k]=1
    while q:
        q_pop=q.popleft()
        now_i=q_pop[0]
        now_j=q_pop[1]
        now_k=q_pop[2]
        for k in d:
            if 0<=now_i+k[0]<l and 0<=now_j+k[1]<r and 0<=now_k+k[2]<c:
                if visit[now_i+k[0]][now_j+k[1]][now_k+k[2]]==0:
                    if list_x[now_i+k[0]][now_j+k[1]][now_k+k[2]]=='.' or list_x[now_i+k[0]][now_j+k[1]][now_k+k[2]]=='E':
                        q.append([now_i+k[0], now_j+k[1], now_k+k[2]])
                        visit[now_i+k[0]][now_j+k[1]][now_k+k[2]]=1+visit[now_i][now_j][now_k]
    if visit[end_i][end_j][end_k]: print("Escaped in", visit[end_i][end_j][end_k]-1, "minute(s).")
    else: print("Trapped!")
    l, r, c=map(int, input().split())
