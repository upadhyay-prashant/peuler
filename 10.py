arr=map(lambda x:0,range(0,2000000))
arr[0]=1
arr[1]=1
for i in range(2,2000000):
    if arr[i]==0:
        temp=i*2
        while temp<2000000:
            arr[temp]=1;
            temp+=i
prime=[]
for i in range(1,2000000):
    if arr[i]==0:
        prime.append(i)
print prime
print sum(prime)
