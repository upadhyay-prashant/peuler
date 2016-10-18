num=1000000
arr=map(lambda x:0,range(0,num+1))
arr[0]=1
arr[1]=1
for i in range(2,num):
    if arr[i]==0:
        temp=i*2
        while temp<=num:
            arr[temp]=1;
            temp+=i
prime=[]
for i in range(1,num):
    if arr[i]==0:
        prime.append(i)
print prime
print prime[10000]
