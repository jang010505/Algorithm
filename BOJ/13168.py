def discount(name, cost):
    if name=="Mugunghwa" or name=="ITX-Saemaeul" or name=="ITX-Cheongchun":
        return 0
    elif name=="S-Train" or name=="V-Train":
        return cost/2
    elif name=="Subway" or name=="Bus" or name=="Taxi" or name=="Airplane" or name=="KTX":
        return cost
n, r=map(int, input().split())
city_tmp=list(input().split())
count=0
city=dict()
info1=[[10e9]*n for i in range(n)]
info2=[[10e9]*n for i in range(n)]
for i in range(n):
    info1[i][i]=0
    info2[i][i]=0
for name in city_tmp:
    city.update({name : count})
    count+=1
m=int(input())
travel_city=list(input().split())
k=int(input())
for k in range(k):
    Type, go, to, cost=input().split()
    cost=int(cost)
    info1[city[go]][city[to]]=min(info1[city[go]][city[to]], cost)
    info2[city[go]][city[to]]=min(info2[city[go]][city[to]], discount(Type, cost))
    info1[city[to]][city[go]]=min(info1[city[to]][city[go]], cost)
    info2[city[to]][city[go]]=min(info2[city[to]][city[go]], discount(Type, cost))
for k in range(n):
    for i in range(n):
        for j in range(n):
            info1[i][j]=min(info1[i][j], info1[i][k]+info1[k][j])
            info2[i][j]=min(info2[i][j], info2[i][k]+info2[k][j])
answer1=0
answer2=0
for i in range(m-1):
    answer1+=info1[city[travel_city[i]]][city[travel_city[i+1]]]
    answer2+=info2[city[travel_city[i]]][city[travel_city[i+1]]]
if answer1<=answer2+r:
    print("No")
else:
    print("Yes")
