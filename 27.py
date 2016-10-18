n=100000
arr=map(lambda x:0,range(0,n))
arr[0]=1
arr[1]=1
for i in range(2,n):
    if arr[i]==0:
        temp=i*2
        while temp<n:
            arr[temp]=1;
            temp+=i
prime=[]
for i in range(1,n):
    if arr[i]==0:
        prime.append(i)
prod=0
count=0
mm1=0
mm2=0
print " done updating prime "
for i in range(0,170):
    for j in range(0,350):
        b=prime[i]
        a=prime[j]-prime[i]-1
        temp=prime[j]
        k=1
        while temp in prime and a<=1000 and b<=1000:
            temp=temp+2*k+1+a
            k=k+1
        print "first prime is %s, second is %s, a= %s, b=%s "%(prime[i],prime[j],a,b)
        if k>count:
            print "updating k=%s, a=%s,b=%s"%(k,a,b)
            count=k
            prod=a*b
            mm1=a
            mm2=b
print "numbers are %s,%s,%s"%(mm1,mm2,count)
