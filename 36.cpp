#include<iostream>
using namespace std;
bool palin_dec(int n){
 //   cout<<"checking palin_dec of "<<n;
    int temp=n;
    int sum=0;
    while(temp>0){
        sum=sum*10+temp%10;
        temp=temp/10;
    }
    if(sum==n)
        return true;
    return false;
}
bool palin_bin(int  n){
//cout<<"checking palin_bin of "<<n;
    int temp=n;
    int a[32];
    for(int i=0;i<32;i++){
        a[i]=0;
    }
    int ind=0;
    while(temp>0){
        int t=temp&1;
        a[ind++]=t;
        temp=temp>>1;
    }
    //TODO 
    for(int i=0;i<ind/2;i++){
        if(a[i]!=a[ind-i-1])
            return false;
    }
    cout<<"\n bin is ";
    for(int i=ind-1;i>=0;i--)
        cout<<" "<<a[i];
    return true;
}
int main(){
    int sum=0;
    for(int i=1;i<1000000;i++){
        if(palin_dec(i)&& palin_bin(i)){
            cout<<"\tnum is "<<i;
            sum+=i;
        }
    }
    cout<<"sum is "<<sum;
    return 0;
}
