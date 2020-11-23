while True:
    try:
        x=int(input())
        if x=='EOF':
            break
        y=1
        cnt=1
        while True:
            if y%x==0:
                print(cnt)
                break
            else:
                y=(y*10)%x+1
                cnt+=1
    except:
        break
