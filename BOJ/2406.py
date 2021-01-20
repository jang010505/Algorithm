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
    else:
        return 0
n, m=map(int, input().split())
count=0
parent=[i for i in range(n+1)]
for i in range(m):
    a, b=map(int, input().split())
    union(a, b)
node=[]
answer_sum=0
answer_list=[]
for i in range(n):
    list_x=list(map(int, input().split()))
    if i!=0:
        for j in range(i+1, n):
            node.append((i+1, j+1, list_x[j]))
node.sort(key=lambda x : x[-1])
for i in range(len(node)):
    if findParent(node[i][0], node[i][1])==0:
        union(node[i][0], node[i][1])
        answer_sum+=node[i][2]
        answer_list.append((node[i][0], node[i][1]))
print(answer_sum, len(answer_list))
for i, j in answer_list:
    print(i, j)
