n=10000
arr=map(lambda x:0,range(0,n))
arr[0]=1
arr[1]=1
myMap={}

def findMap(n):
    res=0
    while n>0:
        ind=n%10
        #if res&(1<<ind):
        #    return -1
        res=res|(1<<ind)
        n=n/10
    return res
def check(val):
    for i in range(0,len(val)):
            for j in range(i+1,len(val)):
                if (val[i]+val[j])/2 in val:
                    print "%s%s%s"%(val[i],(val[i]+val[j])/2,val[j])
for i in range(2,n):
    if arr[i]==0:
        temp=i*2
        while temp<n:
            arr[temp]=1;
            temp+=i
for i in range(1000,n):
    if arr[i]==0:
        res=findMap(i)
        var=[]
        #print "res for %s is %s"%(i,res)
        if res in myMap:
            var=myMap[res]
        else:
            myMap[res]=var
        var.append(i)
for key,value in myMap.iteritems():
    if len(value)>3 and key!=-1:
        check(value)
