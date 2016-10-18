n=1000000
arr=map(lambda x:0,range(0,n))
arr[0]=1
arr[1]=1
myMap={}
for i in range(2,n):
    if arr[i]==0:
        temp=i*2
        while temp<n:
            var=[]
            if temp in myMap:
                var=myMap[temp]
            else:
                myMap[temp]=var
            var.append(i)
            arr[temp]=arr[temp]+1;
            temp+=i

def check(i):
    var=[]
    for j in range(0,3):
        temp=myMap[i+j]
        temp1=myMap[i+j+1]
        for j in range(0,len(temp)):
            if temp[j] in temp1:
                return False
    return True

count=0
for i in range(2,n):
    if arr[i]==4:
        count=count+1
    else:
        count=0
    if count==4:
        if check(i-3)==True:
            print i-3
            break
