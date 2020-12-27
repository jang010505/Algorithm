from collections import deque
n=int(input())
list_x=[]
d=[[1, 0], [-1, 0], [0, 1], [0, -1]]
visit=[[0]*n for i in range(n)]
for i in range(n):
    list_x.append(list(map(int, input().split())))
q=deque()
q.append([0, 0])
visit[0][0]=1
while q:
    q_pop=q.popleft()
    now_i=q_pop[0]
    now_j=q_pop[1]
    jump=list_x[now_i][now_j]
    if now_i==now_j==n-1:
        break
    for k in d:
        if 0<=now_i+jump*k[0]<n and 0<=now_j+jump*k[1]<n:
            if visit[now_i+jump*k[0]][now_j+jump*k[1]]==0:
                visit[now_i+jump*k[0]][now_j+jump*k[1]]=1
                q.append([now_i+jump*k[0], now_j+jump*k[1]])
if visit[n-1][n-1]: print("HaruHaru")
else: print("Hing")
