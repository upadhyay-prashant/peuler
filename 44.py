n=10000
var=[]
for i in range (1,n):
    num=i*(3*i-1)/2
    var.append(num)
for i in range(0,n-1):
    for j in range(i+1,n-1):
        pk=var[j]
        pj=var[i]
        if pk+pj in var and pk-pj in var:
            print pk-pj
