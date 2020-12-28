from collections import deque
n, m=map(int, input().split())
x1, y1, x2, y2=map(int, input().split())
list_x=[]
d=[[1, 0], [-1, 0], [0, 1], [0, -1]]
for i in range(n):
    list_x.append(list(input()))
chk=False
count=0
while chk!=True:
    count+=1
    q=deque()
    q.append([x1-1, y1-1])
    visit=[[0]*m for i in range(n)]
    while q:
        q_pop=q.popleft()
        now_i=q_pop[0]
        now_j=q_pop[1]
        if now_i==x2-1 and now_j==y2-1:
            chk=True
            break
        for k in d:
            i=now_i+k[0]
            j=now_j+k[1]
            if 0<=i<n and 0<=j<m:
                if list_x[i][j]=='1':
                    list_x[i][j]='0'
                    visit[i][j]=1
                elif visit[i][j]==0:
                    q.append([i, j])
                    visit[i][j]=1
print(count)
