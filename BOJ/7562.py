from collections import deque
d=[[2, 1], [2, -1], [-2, 1], [-2, -1], [1, 2], [1, -2], [-1, 2], [-1, -2]]
for _ in range(int(input())):
    n=int(input())
    start_x, start_y=map(int, input().split())
    end_x, end_y=map(int, input().split())
    visit=[]
    for i in range(n):
        visit.append([0]*n)
    q=deque()
    visit[start_x][start_y]=1
    q.append([start_x, start_y, 0])
    while q:
        q_pop=q.popleft()
        x=q_pop[0]
        y=q_pop[1]
        cost=q_pop[2]
        if x==end_x and y==end_y:
            break
        for i in d:
            if 0<=x+i[0]<n and 0<=y+i[1]<n and visit[x+i[0]][y+i[1]]==0:
                q.append([x+i[0], y+i[1], cost+1])
                visit[x+i[0]][y+i[1]]=1
    print(cost)
