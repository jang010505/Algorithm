n=int(input())
k=int(input())
d=[]
x=[0]*n
for i in range(n):
    d.append([])
for i in range(k):
    a, b=map(int, input().split())
    d[a-1].append(b-1)
    d[b-1].append(a-1)
x[0]=1
q=[]
cnt=0
q.append(0)
while len(q)!=0:
    com=q.pop(0)
    for i in d[com]:
        if x[i]==0:
            x[i]=1
            q.append(i)
            cnt+=1
print(cnt)
