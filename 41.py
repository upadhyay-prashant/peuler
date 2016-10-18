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
def check(num):
    ab=map(lambda x:0,range(0,10))
    while num>0:
        ab[num%10]=1
        num=num/10
    for i in range(1,8):
        if ab[i]==0:
            return False
    return True
for i in range(100000,1000000):
    if arr[i]==0 and check(i)==True:
        print i
