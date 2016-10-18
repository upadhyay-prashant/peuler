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
palin=[]
for pr in prime:
    temp=pr
    count=0
    check=True
    while temp>0 and check==True:
        count=count+1
        if temp%10==2 and temp!=2:
            check=False
        if temp%10==5 and temp!=5:
            check=False
        temp=temp/10
    if check==False:
        continue
    temp=pr
    co=count
    chh=[]
    while co >0 and check==True:
        co=co-1
        ch=temp%10
        temp=temp/10
        temp=temp+ch*(10**(count-1))
        if temp not in prime:
            check=False
        elif temp not in chh :
            chh.append(temp)
    if check==True:
        for k in chh:
            palin.append(k)
print "numbers are %s"%(len(palin))
