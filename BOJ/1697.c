n, k=map(int, input().split())
visit=[0]*100001
cnt=0
q=[]
q.append([n, 0])
visit[n]=1
while len(q)!=0:
    q_pop=q.pop(0)
    now=q_pop[0]
    cost=q_pop[1]
    if now==k: break
    if now-1>=0 and visit[now-1]==0:
        q.append([now-1, cost+1])
        visit[now-1]=1
    if now+1<=100000 and visit[now+1]==0:
        q.append([now+1, cost+1])
        visit[now+1]=1
    if 2*now<=100000 and visit[2*now]==0:
        q.append([2*now, cost+1])
        visit[2*now]=1
print(cost)
