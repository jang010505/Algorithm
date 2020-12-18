town_count, town_N = map(int, input().split())
town_list = []
for i in range(town_count):
    town_list.append([])
for i in range(town_N):
    a, b = map(int,input().split())
    town_list[a-1].append(b-1)
    town_list[b-1].append(a-1)
town = [0]*town_count
count = int(input())
town_X = list(map(int, input().split()))
for i in town_X:
    town[i-1]=1
res=[]
for i in range(town_count):
    chk=1
    for j in town_list[i]:
        if town[j]==0 and town[i]==1:
            chk=0
    if town[i]==1 and chk==1:
        res.append(i)
for i in res:
    for j in town_list[i]:
        town[j]=0
    town[i]=0
z=1
for i in range(town_count):
    if town[i]==1:
        z=0
if z==0:
    print(-1)
else:
    print(len(res))
    for i in res:
        print(i+1, end=' ')
