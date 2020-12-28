from collections import deque
r,c=map(int, input().split())
list_x=[]
for i in range(r):
    list_x.append(list(input()))
visit_cnt=[[0]*c for i in range(r)]
visit_time=[[0]*c for i in range(r)]
d=[[1, 0], [-1, 0], [0, 1], [0, -1]]
for _ in range(3):
    a, b=map(int, input().split())
    visit=[[0]*c for i in range(r)]
    q=deque()
    q.append([a-1, b-1])
    visit[a-1][b-1]=1
    visit_cnt[a-1][b-1]+=1
    while q:
        now_i, now_j=q.popleft()
        for t in d:
            i=now_i+t[0]
            j=now_j+t[1]
            if 0<=i<r and 0<=j<c:
                if visit[i][j]==0 and list_x[i][j]=='0':
                    q.append([i, j])
                    visit[i][j]=1+visit[now_i][now_j]
                    visit_cnt[i][j]+=1
                    visit_time[i][j]=max(visit[i][j], visit_time[i][j])
result=1000000000
count=0
for i in range(r):
    for j in range(c):
        if visit_cnt[i][j]==3:
            if visit_time[i][j]<result:
                result=visit_time[i][j]
                count=1
            elif visit_time[i][j]==result:
                count+=1
if count:
    print(result-1)
    print(count)
else:
    print(-1)
