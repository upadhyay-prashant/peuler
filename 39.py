squares=map(lambda x:0,range(1,1000000))
for i in range(1,1000):
    squares[i*i]=i
arr={}
for i in range (1,1000):
    for j in range(1,1000):
        su=i*i+j*j
        if su>=1000000:
            continue
        c=squares[su]
        if c!=0:
            temp=c+i+j
            if temp<1001:
                ar1={'c':c,'i':i,'j':j}
                if temp in arr:
                    ch=arr[temp]
                    ch.append(ar1)
                else:
                    arrr=[ar1]
                    arr[temp]=arrr
ma=0
arr_ans=0
p=0
for key,value in arr.iteritems():
    if(len(value)>ma):
        ma=len(value)
        arr_ans=value
        p=key
print "sum is %s and tupes are %s"%(p,arr_ans)



