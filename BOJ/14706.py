from collections import deque
n, m=map(int, input().split())
list_x=[]
d=[[1, 1], [1, 0], [1, -1], [0, 1], [0, -1], [-1, 1], [-1, 0], [-1, -1]]
for i in range(n):
    list_x.append(list(map(int, input().split())))
result=0
for i in range(n):
    for j in range(m):
        if list_x[i][j]==1:
            result+=1
            q=deque()
            q.append([i, j])
            list_x[i][j]=0
            while q:
                q_pop=q.popleft()
                now_i=q_pop[0]
                now_j=q_pop[1]
                for k in d:
                    I=now_i+k[0]
                    J=now_j+k[1]
                    if 0<=I<n and 0<=J<m:
                        if list_x[I][J]==1:
                            q.append([I, J])
                            list_x[I][J]=0
print(result)
