from collections import deque
n, m=map(int, input().split())
list_x=[]
virus=deque()
for i in range(n):
    list_x.append(list(map(int, input().split())))
    for j in range(m):
        if list_x[i][j]==2:
            virus.append([i, j])
result=0
d=[[1, 0], [-1, 0], [0, 1], [0, -1]]
for i in range(n*m-2):
    if list_x[i//m][i%m]!=0:
        continue
    for j in range(i+1, n*m-1):
        if list_x[j//m][j%m]!=0:
            continue
        for k in range(j+1, n*m):
            if list_x[k//m][k%m]!=0:
                continue
            visit=[[0]*m for v in range(n)]
            for v in range(n):
                for t in range(m):
                    visit[v][t]=list_x[v][t]
            q=deque()
            visit[i//m][i%m]=1
            visit[j//m][j%m]=1
            visit[k//m][k%m]=1
            for v in range(len(virus)):
                q.append(virus[v])
            while q:
                q_pop=q.popleft()
                now_i=q_pop[0]
                now_j=q_pop[1]
                for v in d:
                    I=now_i+v[0]
                    J=now_j+v[1]
                    if 0<=I<n and 0<=J<m:
                        if visit[I][J]==0:
                            q.append([I, J])
                            visit[I][J]=1
            cnt=0
            for I in range(n):
                for J in range(m):
                    if visit[I][J]==0:
                        cnt+=1
            if cnt>result:
                result=cnt
print(result)
