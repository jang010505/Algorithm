xa, ya, xb, yb, xc, yc=map(int, input().split())
if (xa==xb and xb==xc) or (ya==yb and yb==yc):
    print(-1)
    exit()
if xa!=xb and xa!=xc and ya!=yb and ya!=yc: 
    if (ya-yb)/(xa-xb)==(ya-yc)/(xa-xc):
        print(-1)
        exit()
res1=2*((xa-xb)**2+(ya-yb)**2)**0.5+2*((xa-xc)**2+(ya-yc)**2)**0.5
res2=2*((xa-xb)**2+(ya-yb)**2)**0.5+2*((xb-xc)**2+(yb-yc)**2)**0.5
res3=2*((xb-xc)**2+(yb-yc)**2)**0.5+2*((xa-xc)**2+(ya-yc)**2)**0.5
print("%.10f" %(max(res1, res2, res3)-min(res1, res2, res3)))
