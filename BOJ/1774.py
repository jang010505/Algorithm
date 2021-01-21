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
n, m=map(int, input().split())
x_list=list()
node=list()
parent=[i for i in range(n+1)]
for i in range(n):
    a, b=map(int, input().split())
    x_list.append((a, b))
for i in range(m):
    a, b=map(int, input().split())
    union(a, b)
for i in range(n):
    for j in range(i+1, n):
        node.append((i+1, j+1, ((x_list[i][0]-x_list[j][0])**2+(x_list[i][1]-x_list[j][1])**2)**(1/2)))
answer=0
node.sort(key=lambda x : x[-1])
for i in range(len(node)):
    if parentFind(node[i][0], node[i][1])==0:
        union(node[i][0], node[i][1])
        answer+=node[i][2]
print(format(answer, ".2f"))
