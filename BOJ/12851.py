from collections import deque
n, k=map(int, input().split())
visit=[0]*100001
cnt=0
q=deque()
q.append([n, 0])
chk=1000000000
cnt=0
while q:
    q_pop=q.popleft()
    now=q_pop[0]
    cost=q_pop[1]
    visit[now]=1
    if now==k and chk==1000000000:
        chk=cost
        cnt+=1
    elif now==k and chk==cost and chk!=1000000000:
        cnt+=1
    if cost>chk:
        break
    if now-1>=0 and visit[now-1]==0:
        q.append([now-1, cost+1])
    if now+1<=100000 and visit[now+1]==0:
        q.append([now+1, cost+1])
    if 2*now<=100000 and visit[2*now]==0:
        q.append([2*now, cost+1])
print(chk)
print(cnt)
