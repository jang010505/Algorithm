for _ in range(int(input())):
    info=input()
    if '.' in info:
        m, d, y=map(int, info.split('.'))
    else:
        d, m, y=map(int, info.split('/'))
    print("%02d.%02d.%04d %02d/%02d/%04d" %(m, d, y, d, m, y))
