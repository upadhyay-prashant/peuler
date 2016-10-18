n=10000
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
print prime
