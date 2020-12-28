from collections import deque
from itertools import combinations

n, m=map(int, input().split())
list_x=[]
virus=[]
d=[[1, 0], [-1, 0], [0, 1], [0, -1]]
for i in range(n):
    list_x.append(list(map(int, input().split())))
    for j in range(n):
        if list_x[i][j]==2:
            virus.append([i, j])
            list_x[i][j]=0
list_c=list(combinations(virus, m))
result=[]
for t in list_c:
    q=deque()
    visit=[[0]*n for j in range(n)]
    for i in range(n):
        for j in range(n):
            visit[i][j]=list_x[i][j]
    for i in t:
        visit[i[0]][i[1]]=1
        q.append([i[0], i[1], 0])
    while q:
        q_pop=q.popleft()
        now_i=q_pop[0]
        now_j=q_pop[1]
        cost=q_pop[2]
        for v in d:
            i=now_i+v[0]
            j=now_j+v[1]
            if 0<=i<n and 0<=j<n and visit[i][j]==0:
                visit[i][j]=1
                q.append([i, j, cost+1])
    chk=True
    for i in range(n):
        for j in range(n):
            if visit[i][j]==0:
                chk=False
    if chk:
        result.append(cost)
if len(result): print(min(result))
else: print(-1)
