a=[17,13,11,7,5,3,2]
numToIndMap={}
locToNumMap={}
for ch in range(0,len(a)):
    i=a[ch]
    num=i
    while num<1000:
        var={}
        var1={}
        if i in numToIndMap:
            var=numToIndMap[i]
            var1=locToNumMap[i]
        else:
            numToIndMap[i]=var
            locToNumMap[i]=var1
        digits=0
        if i==17:
            temp=num;
            for j in range(0,3):
                ind=temp%10
                temp=temp/10
                if digits !=-1 and digits&(1<<ind):
                    digits=-1
                    #print "for %s came out to be -1"%num
                elif digits!=-1:
                    digits=digits|(1<<ind)
        else:
            temp=num%100
            temp1=numToIndMap[a[ch-1]]
            if temp in temp1:
                digits=temp1[temp]
            else:
                digits=-1
                #print "num %s not found in above array"%(num)
            #print "digit is %s"%(digits)
            if digits!=-1:
                ind=num/100
                #print "ind is %s"%ind
                if digits&(1<<ind):
                    #print "repeating digits found for %s and digits are %s"%(num,digits)
                    digits=-1
                else:
                    digits=digits|(1<<ind)
        #print "digits for %s is %s"%(num,digits)
        if digits!=-1:
            var[num/10]=digits
            var1[num/10]=num
        num=num+i
    print "length is %s , %s\t\t %s"%(len(numToIndMap[i]),numToIndMap[i],locToNumMap[i])
i=len(a)-1
num=a[i]
arr=locToNumMap[num]
def find_pow(num):
    for i in range(0,10):
        if num==(1<<i):
            return i
    return -1
sum=0
for key,value in arr.iteritems():
    c=key
    j=i;
    check=find_pow(1023-((numToIndMap[num])[key]))
    while j>=0:
        chh=locToNumMap[a[j]]
        b=chh[c]
        if j!=len(a)-1:
            b=b%10
            check=check*10+b
        else:
            check=check*1000+b
        c=chh[c]%100
        j=j-1
    print check
    sum=sum+check
print sum
