def find(num):
    if parent[num]==num:
        return num
    parent[num]=find(parent[num])
    return parent[num]
def union(num1, num2):
    a=find(num1)
    b=find(num2)
    if a!=b:
        parent[b]=a
def parentFind(num1, num2):
    a=find(num1)
    b=find(num2)
    if a!=b:
        return 0
    else:
        return 1
n=int(input())
node=list()
x_list=list()
answer_sum=0
for i in range(n):
    a, b, c=map(int, input().split())
    x_list.append((a, b, c, i))
for i in range(3):
    x_list.sort(key=lambda x : x[i])
    prv=x_list[0][3]
    for j in range(1, n):
        now=x_list[j][3]
        node.append((prv, now, abs(x_list[j][i]-x_list[j-1][i])))
        prv=now
parent=[i for i in range(n)]
node.sort(key = lambda x : x[-1])
for go, to, cost in node:
    if parentFind(go, to)==0:
        union(go, to)
        answer_sum+=cost
print(answer_sum)
