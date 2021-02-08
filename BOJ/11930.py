def dist(dx, dy, dz):
    return dx**2+dy**2+dz**2
n=int(input())
point=list()
sum_x=0
sum_y=0
sum_z=0
for i in range(n):
    point.append(list(map(int, input().split())))
    sum_x+=point[i][0]
    sum_y+=point[i][1]
    sum_z+=point[i][2]
now_x=sum_x/n
now_y=sum_y/n
now_z=sum_z/n
tmp=0.1
distance=0
for i in range(50000):
    index=0
    distance=dist(point[0][0]-now_x, point[0][1]-now_y, point[0][2]-now_z)
    for j in range(1, n):
        distance_tmp=dist(point[j][0]-now_x, point[j][1]-now_y, point[j][2]-now_z)
        if distance<distance_tmp:
            distance=distance_tmp
            index=j
    now_x+=(point[index][0]-now_x)*tmp
    now_y+=(point[index][1]-now_y)*tmp
    now_z+=(point[index][2]-now_z)*tmp
    tmp*=0.998
print("%.2f" %(distance)**(1/2))
