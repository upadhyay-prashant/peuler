n=1000000
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
myPrimes=[]
arr[0]=0
for i in range(0,len(prime)):
    if prime[i]<12:
        continue;
    temp1=prime[i]
    temp2=prime[i]
    check=True
    count=0
    while temp1!=0:
        rem=temp1%10
        if rem==2  or rem==4 or rem == 6 or rem ==8 :
            check=False
            break
        temp1=temp1/10
        count=count+1
        if arr[temp1]!=0:
            check=False
            break
    if check==False:
        continue
    count=count-1
    while temp2>10:
        rem=temp2/10**count
        temp2=temp2%10**count
        count=count-1
        if arr[temp2]!=0:
            check=False
            break
    if check==True:
        myPrimes.append(prime[i])
myPrimes.append(23)
print sum(myPrimes)
