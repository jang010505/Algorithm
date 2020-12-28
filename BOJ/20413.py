n=int(input())
s, g, p, d=map(int, input().split())
t=input()
res=0
tmp=0
for i in t:
    if i=='B':
        res+=s-1-tmp
        tmp=s-1-tmp
    if i=='S':
        res+=g-1-tmp
        tmp=g-1-tmp
    if i=='G':
        res+=p-1-tmp
        tmp=p-1-tmp
    if i=='P':
        res+=d-1-tmp
        tmp=d-1-tmp
    if i=='D':
        res+=d
print(res)
