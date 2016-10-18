#include<iostream>
#include<vector>
using namespace std;
int power(int n,int po){
    int sum=1;
    for(int i=0;i<po;i++)
        sum*=n;
    return sum;
}
int main(){
    int len=1000000;
    int a[len];
    for(int i=0;i<len;i++)
        a[i]=0;
    for(int i=2;i<len;i++)
    {
        int temp=i*2;
        if(a[i]==0)
            while(temp<len){
                a[temp]=1;
                temp=temp+i;
            }
    }
    int count=0;
    for(int i=2;i<len;i++){
        int temp=i;
        int po=0;
        bool ch=true;
        while(temp>0){
            if(temp%2==0 || temp%5==0){
                ch=false;
                break;
            }
            temp=temp/10;
            po++;
        }
        if(!ch)
            continue;
        temp=i;
        int it=po;
        int count_temp=0;
        while(it>0 && ch){
            it--;
            temp=temp/10+(temp%10)*power(10,po-1);
            if(a[temp]==0){
                count_temp++;
                a[temp]=1;
            }
            else{
                count_temp=0;
                ch=false;
            }
        }
        count=count+count_temp;
        if(ch==true)
            cout<<"number is "<<i;
    }
    cout<<"count is "<<count+3;
    //2,5,11 are missed by the algo and added to anser deliberately
    return 0;
}
