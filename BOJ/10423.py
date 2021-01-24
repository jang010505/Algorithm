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
n, m, k=map(int, input().split())
node=list()
answer_sum=0
x_list=list(map(int, input().split()))
parent=[i for i in range(n+1)]
for i in range(k-1):
    for j in range(1, k):
        union(x_list[i], x_list[j])
for i in range(m):
    u, v, w=map(int, input().split())
    node.append((u, v, w))
node.sort(key = lambda x : x[-1])
for go, to, cost in node:
    if parentFind(go, to)==0:
        union(go, to)
        answer_sum+=cost
print(answer_sum)
