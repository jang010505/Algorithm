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
node=[]
parent=[i for i in range(n+1)]
answer_sum=0
list_x=list(input().split())
visit=[0]*(n+1)
for i in range(m):
    a, b, c=map(int, input().split())
    node.append((a, b, c))
node.sort(key=lambda x : x[-1])
for i in range(m):
    if findParent(node[i][0], node[i][1])==0 and list_x[node[i][0]-1]!=list_x[node[i][1]-1]:
        visit[node[i][0]]=1
        visit[node[i][1]]=1
        union(node[i][0], node[i][1])
        answer_sum+=node[i][2]
for i in range(1, n+1):
    if visit[i]==0:
        print(-1)
        exit()
print(answer_sum)
