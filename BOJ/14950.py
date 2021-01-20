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
n, m, t=map(int, input().split())
node=[]
parent=[i for i in range(n+1)]
answer_sum=0
answer_cnt=0
for i in range(m):
    a, b, c=map(int, input().split())
    node.append((a, b, c))
node.sort(key=lambda x : x[-1])
for i in range(m):
    if findParent(node[i][0], node[i][1])==0:
        union(node[i][0], node[i][1])
        answer_sum+=answer_cnt*t+node[i][2]
        answer_cnt+=1
print(answer_sum)
