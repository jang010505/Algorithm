x, y=map(int, input().split())
if y<0:
    if x<0:
        if x%y!=0:
            print(x//y+1)
            print(x-(x//y+1)*y)
        else:
            print(x//y)
            print(x%y)
    else:
        if x%y!=0: print(x//y+1)
        else: print(x//y)
        print(x%abs(y))
else:
    print(x//y)
    print(x%y)
