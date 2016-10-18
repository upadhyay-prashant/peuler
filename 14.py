c=1
arr={1:1}
max=0
num=0
for i in range(2,1000000):
    count=0
    temp=i
    while i not in arr:
        count=count+1
        if i%2==0:
            i=i/2
        else:
            i=i*3+1
    arr[temp]=count+arr[i]
#    print "udpating for",i," ",arr[temp]
    if max<arr[temp]:
        max=arr[temp]
        num=temp
print "temp is ",num," num is ",max
