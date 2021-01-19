def find(num):
    if parent[num]==num:
        return num
    else:
        parent[num]=find(parent[num])
        return parent[num]
def union(num1, num2):
    a=find(num1)
    b=find(num2)
    if a!=b:
        parent[b]=a
def findParent(num1, num2):
    a=find(num1)
    b=find(num2)
    if a==b:
        return 1
    elif a!=b:
        return 0
n=int(input())
parent=[i for i in range(n+1)]
node=[]
for i in range(n):
    list_x=list(map(int, input().split()))
    for j in range(i+1, n):
        node.append((i, j, list_x[j]))
node.sort(key = lambda x : x[-1])
answer=0
for i in range(len(node)):
    if findParent(node[i][0], node[i][1])==0:
        union(node[i][0], node[i][1])
        answer+=node[i][2]
print(answer)
