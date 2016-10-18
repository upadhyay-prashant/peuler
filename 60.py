length=100000000
arr=map(lambda x:0,range(0,length))
arr[0]=1
arr[1]=1
for i in range(2,length):
    if arr[i]==0:
        temp=2*i
        while temp<length:
            arr[temp]=1
            temp=temp+i
prime=[]
print "sieve done"
for i in range(2,10000):
    if arr[i]==0:
        prime.append(i)
maps={}
print "prime number isolated"
for i in range(1,len(prime)):
    for j in range(i+1,len(prime)):
        temp=prime[j]
        temp2=0
        while temp>0:
            temp2=temp2*10+temp%10
            temp=temp/10
        temp3=0
        temp=prime[i]
        while temp>0:
            temp3=temp3*10+temp%10
            temp=temp/10
        num1=prime[i]
        num2=prime[j]
        while temp2>0:
            num1=num1*10+temp2%10
            temp2=temp2/10
        while temp3>0:
            num2=num2*10+temp3%10
            temp3=temp3/10
        if num1 <length and num2<length and arr[num1]==0 and arr[num2]==0:
            temp=[]
            if i not in maps:
                maps[i]=temp
            else:
                temp=maps[i]
            temp.append(prime[j])
            temp=[]
            if j not in maps:
                maps[j]=temp
            else:
                temp=maps[j]
            temp.append(prime[i])

def check(temp, i):
    if len(temp)==5:
        return 1
    print "temp is %s"%(temp)
    if prime[i+1] in maps[i]:
       return check(temp.append(prime[i+1]),i+1)
    return 0


for i in range(1,len(prime)):
    temp=[]
    temp.append(prime[i])
    if check(temp,i)==1:
        print temp


for key,value in maps.iteritems():
    if len(value)>4:
        print value

