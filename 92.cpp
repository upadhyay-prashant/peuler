#include<iostream>
using namespace std;
int sum_s(int i)
{
    int sum=0;
    while(i>0)
    {
        sum=sum+(i%10)*(i%10);
        i=i/10;
    }
    return sum;
}
int check(int a[],int i){
    int sum=sum_s(i);
    cout<<"sum got from function is "<<sum;
    if(a[sum]!=-1)
        return a[sum];
    if(sum==1){
        return 0;
    }
    if(sum==89)
        return 1;
    int res=check(a,sum);
    a[i]=res;
    return res;
}
int main(){
    int len=10000000;
    int *a=new int[len];
    for(int i=0;i<len;i++)
        a[i]=-1;
    int count=0;
   // cout<<"init done";
    for(int i=1;i<len;i++){
        cout<<"\ncheckin i="<<i;
        if(check(a,i)==0){
            cout<<" sum=1";
            a[i]=0;
        }
        else{
            cout<<"sum=89";
            a[i]=1;
            count++;
        }
    }
    cout<<"count is "<<count;
    return 0;
}
