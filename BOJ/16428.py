x, y=map(int, input().split())
if y<0:
    print(x//y+1)
    print(abs(x%y)-1)
else:
    print(x//y)
    print(x%y)
