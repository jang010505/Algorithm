start_h, start_m=map(int, input().split())
end_h, end_m=map(int, input().split())
n=int(input())
count=0
while 1:
    if start_h%10==n or start_h//10==n or start_m%10==n or start_m//10==n:
        count+=1
    if start_h==end_h and start_m==end_m:
        print(count)
        break
    start_m+=1
    if start_m==60:
        start_m=0
        start_h+=1
