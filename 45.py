tr=map(lambda x:0,range(0,100000000))
pe=map(lambda x:0,range(0,100000000))
he=map(lambda x:0,range(0,100000000))
count=1
term=0
while True:
    sum1=count*(count+1)/2
    sum2=count*(3*count-1)/2
    sum3=count*(2*count-1)
    tr[sum1]=count
    pe[sum2]=count
    he[sum3]=count
    if he[sum1]!=0 and pe[sum1]!=0:
        print "value is %s, terms are %s %s %s"%(sum1,count,pe[sum1],he[sum1])
        term=term+1
        if term==3:
            break
    count=count+1
