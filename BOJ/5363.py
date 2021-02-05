for _ in range(int(input())):
    info=list(input().split())
    for i in range(2, len(info)):
        print(info[i], end=' ')
    print(info[0], info[1])
