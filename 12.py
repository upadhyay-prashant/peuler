arr=map(lambda x:0,range(0,10000))
arr[0]=1
arr[1]=1
for i in range(2,10000):
    if arr[i]==0:
        temp=i*2
        while temp<10000:
            arr[temp]=1;
            temp+=i
prime=[]
for i in range(1,10000):
    if arr[i]==0:
        prime.append(i)
max=0
for i in range(1,10000):
    sum=(i*(i+1))/2
    factors={}
    for j in range(0,len(prime)):
        temp=sum
        count=0
        if prime[j]>temp:
            break;
        while temp>0:
            if temp%prime[j]==0:
                count=count+1
                temp=temp/prime[j]
            else:
                temp=0
        if count>0:
            factors[prime[j]]=count
    count=1
    for key,value in factors.iteritems():
        count=count*(value+1)
#    print "for sum ", sum, "factors are ",factors," values= ",count
    if count>max:
        max=count
    if count>500:
        print " value found is ",sum,"  ",count," and i is ",i
        break
print "max is ",max

