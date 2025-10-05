wt=[5,10,20,30]
val=[200,120,80,60]
ratio=[]
value=0
cap=20
i=0
k=0
b=0
h=0
for i in range(4):
    k=wt[i]
    b=val[i]
    h=b/k
    ratio.append(h)
    if cap>=wt[i]:
        cap=cap-wt[i]
        value=value+val[i]
        print(value)    

    else :
        value=value+(ratio[i]*cap)
        print(value)
        break 
    
print(value)
print(ratio)
