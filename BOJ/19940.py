for _ in range(int(input())):
    n=int(input())
    a, b, c, d, e=0, 0, 0, 0, 0
    a+=n//60
    n%=60
    if n>35:
        a+=1
        c=6-(n+5)//10
        n%=10
        if n<5:
            d+=n
        else:
            e+=10-n
    else:
        b=(n+4)//10
        n%=10
        if n<6:
            d+=n
        else:
            e+=10-n
    print(a, b, c, d, e)
