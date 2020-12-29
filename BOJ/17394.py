from collections import deque
prime=[0]*1000001
prime[0]=1
prime[1]=1
i=2
while i*i<=1000000:
    if prime[i]==1:
        i+=1
        continue
    j=i
    while i*j<=1000000:
        prime[i*j]=1
        j+=1
    i+=1
for _ in range(int(input())):
    n, a, b=map(int, input().split())
    q=deque()
    q.append(n)
    visit=[0]*1000001
    visit[n]=1
    chk=0
    while q:
        now=q.popleft()
        if prime[now]==0 and a<=now<=b:
            chk=now
            break
        if visit[now//3]==0:
            visit[now//3]=1+visit[now]
            q.append(now//3)
        if visit[now//2]==0:
            visit[now//2]=1+visit[now]
            q.append(now//2)
        if now+1<=110000 and visit[now+1]==0:
            visit[now+1]=1+visit[now]
            q.append(now+1)
        if now>0 and visit[now-1]==0:
            visit[now-1]=1+visit[now]
            q.append(now-1)
    if chk: print(visit[chk]-1)
    else: print(-1)
