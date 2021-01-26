def find(num):
    if parent[num]==num:
        return num
    else:
        parent[num]=find(parent[num])
        return parent[num]
def union(num1, num2):
    num1=find(num1)
    num2=find(num2)
    if num1!=num2:
        parent[num1]=num2
        return 1
    else:
        return 0
n, m=map(int, input().split())
node=list()
parent=[i for i in range(n+1)]
answer=0
for i in range(m):
    node.append(list(map(int, input().split())))
node.sort(key=lambda x : x[-1])
node.reverse()
for go, to, cost in node:
    if union(go, to):
        answer+=cost
for i in range(1, n):
    if union(i, i+1):
        answer=-1
        break
print(answer)
