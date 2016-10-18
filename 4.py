def palin(sum):
    temp=sum
    temp1=0
    while temp>0:
        rem=temp%10
        temp1=temp1*10+rem
        temp=temp/10
    if temp1==sum:
        return 1
    return 0

p=0
for i in xrange(101,1000):
    for j in xrange(101,1000):
        sum=i*j
        if palin(sum)==1:
            if p<sum:
                p=sum
                print p,i,j
print p
