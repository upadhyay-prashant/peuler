arr=map(lambda x:0,range(0,21))
arr[0]=1
arr[1]=1
for i in range(2,20):
    if arr[i]==0:
        temp=i*2
        while temp<=20:
            arr[temp]=1;
            temp+=i
prime=[]
for i in range(1,20):
    if arr[i]==0:
        prime.append(i)
count=map(lambda x:0,prime)
