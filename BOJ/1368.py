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
parent=[i for i in range(n+1)]
for i in range(n):
    node.append((i+1, 0, int(input())))
for i in range(n):
    x_list=list(map(int, input().split()))
    for j in range(i+1, n):
        node.append((i+1, j+1, x_list[j]))
node.sort(key = lambda x : x[-1])
answer=0
for i, j, cost in node:
    if parentFind(i, j)==0:
        union(i, j)
        answer+=cost
print(answer)
