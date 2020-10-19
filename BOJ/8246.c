a, b, c=map(int,input().split())
print((a//c)*(b//c)-max(0,a//c-2)*max(0,b//c-2))
