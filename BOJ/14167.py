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
def parentFind(num1, num2):
    if find(num1)==find(num2):
        return 1
    else:
        return 0
n=int(input())
x_list=list()
node=list()
for i in range(n):
    x, y=map(int, input().split())
    x_list.append((x, y))
for i in range(n):
    for j in range(i+1, n):
        node.append((i+1, j+1, (x_list[i][0]-x_list[j][0])**2+(x_list[i][1]-x_list[j][1])**2))
node.sort(key=lambda x : x[-1])
parent=[i for i in range(n+1)]
answer=[]
for i in range(len(node)):
    if parentFind(node[i][0], node[i][1])==0:
        union(node[i][0], node[i][1])
        answer.append(node[i][2])
print(max(answer))
