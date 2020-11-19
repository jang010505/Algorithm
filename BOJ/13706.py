x=int(input())
r=10**401
l=1
while l<=r:
    mid=(r+l)//2
    if x==mid**2:
        print(mid)
        break
    elif x>mid**2:
        l=mid+1
    elif x<mid**2:
        r=mid-1
