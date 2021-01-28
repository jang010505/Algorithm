import sys
n, k, t=map(int, input().split())
for _ in range(t):
    start, end=map(int, sys.stdin.readline().split())
    if k==1:
        print(abs(start-end))
    else:
        count=0
        while start!=end:
            while start>end:
                start=(start+k-2)//k
                count+=1
            while start<end:
                end=(end+k-2)//k
                count+=1
        print(count)
