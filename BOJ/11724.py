n, m=map(int, input().split())
list_=[]
for i in range(n):
    list_.append([])
for i in range(m):
    a, b=map(int, input().split())
    list_[a-1].append(b-1)
    list_[b-1].append(a-1)
visit=[0]*n
cnt=0
q=[]
while True:
    z=1
    for i in range(n):
        if visit[i]==0:
            z=0
            q.append(i)
            cnt+=1
            break
    if z==1:
        break
    while len(q)!=0:
        now=q.pop(0)
        visit[now]=cnt
        for i in list_[now]:
            if visit[i]==0:
                visit[i]=cnt
                q.append(i)
print(cnt)
