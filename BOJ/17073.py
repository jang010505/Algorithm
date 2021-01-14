n, w=map(int, input().split())
node=[0]*(n+1)
count=0
for i in range(n-1):
    a, b=map(int, input().split())
    node[a]+=1
    node[b]+=1
for i in range(2, n+1):
    if node[i]==1:
        count+=1
print(w/count)
