#include<iostream>
using namespace std;
int main(){
    int a[10];
    a[0]=1;
    for(int i=2;i<10;i++){
        a[i-1]=a[i-2]*i;
    }
    int num=0;
    for(int i=3;i<100000;i++){
        int temp=i;
        int sum=0;
        while(temp>0){
            int check=temp%10-1;
            if(check==-1)
                check=0;
            sum+=a[check];
            temp=temp/10;
        }
        if(sum==i){
            cout<<"\n num is num"<<i;
            num=num+i;
        }
    }
    cout<<"\n sum is "<<num;
}
