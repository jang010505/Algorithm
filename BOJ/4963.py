from collections import deque
a, b=map(int, input().split())
x=[[1, 1], [1, 0], [1, -1], [0, 1], [0, -1], [-1, 1], [-1, 0], [-1, -1]]
while a!=0 or b!=0:
    visit=[]
    cnt=0
    for i in range(b):
        visit.append(list(map(int, input().split())))
    for i in range(b):
        for j in range(a):
            if visit[i][j]==1:
                q=deque()
                q.append([i, j])
                visit[i][j]=0
                cnt+=1
                while q:
                    q_pop=q.popleft()
                    I=q_pop[0]
                    J=q_pop[1]
                    for k in x:
                        if 0<=I+k[0]<b and 0<=J+k[1]<a and visit[I+k[0]][J+k[1]]==1:
                            q.append([I+k[0], J+k[1]])
                            visit[I+k[0]][J+k[1]]=0
    print(cnt)
    a, b=map(int, input().split())
