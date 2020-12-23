from collections import deque
n, m, k=map(int, input().split())
d=[]
for i in range(n):
    d.append([0]*m)
for i in range(k):
    a, b=map(int, input().split())
    d[a-1][b-1]=1
res=0
for i in range(n):
    for j in range(m):
        if d[i][j]:
            q=deque()
            q.append([i, j])
            d[i][j]=0
            cost=1
            while q:
                q_pop=q.popleft()
                I=q_pop[0]
                J=q_pop[1]
                if I-1>=0 and d[I-1][J]:
                    q.append([I-1, J])
                    d[I-1][J]=0
                    cost+=1
                if J-1>=0 and d[I][J-1]:
                    q.append([I, J-1])
                    d[I][J-1]=0
                    cost+=1
                if I+1<n and d[I+1][J]:
                    q.append([I+1, J])
                    d[I+1][J]=0
                    cost+=1
                if J+1<m and d[I][J+1]:
                    q.append([I, J+1])
                    d[I][J+1]=0
                    cost+=1
            if cost>res:
                res=cost
print(res)
