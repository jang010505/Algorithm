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
n, m, k=map(int, input().split())
parent=[i for i in range(n+1)]
node=[]
list_x=list(map(int, input().split()))
for i in range(n):
    node.append((0, i+1, list_x[i]))
union_set=set()
for i in range(m):
    a, b=map(int, input().split())
    union_set.add((min(a, b), max(a, b)))
for i in range(n-1):
    if (i+1, i+2) not in union_set:
        union(i+1, i+2)
if (1, n) not in union_set:
    union(1, n)
answer_sum=0
node.sort(key=lambda x : x[-1])
for i in range(len(node)):
    if findParent(node[i][0], node[i][1])==0:
        union(node[i][0], node[i][1])
        answer_sum+=node[i][2]
if answer_sum<=k or m<=1:
    print("YES")
else:
    print("NO")
