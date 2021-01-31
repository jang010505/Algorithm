n=int(input())
info=[[100000000]*(26) for i in range(26)]
for i in range(26):
    info[i][i]=0
for i in range(n):
    a, IS, b=input().split()
    info[ord(a)-97][ord(b)-97]=1
for k in range(26):
    for i in range(26):
        for j in range(26):
            info[i][j]=min(info[i][j], info[i][k]+info[k][j])
n=int(input())
for i in range(n):
    a, IS, b=input().split()
    if info[ord(a)-97][ord(b)-97]!=100000000:
        print("T")
    else:
        print("F")
