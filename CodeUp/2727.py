n=int(input())
for i in range(n):
    a, b=map(int, input().split())
    print("Scenario #%d:" %(i+1))
    res=((b-a)*(b+a))//2+(b+a)//2
    if abs(a+b)%2==1: res+=1
    print(res, "\n")
