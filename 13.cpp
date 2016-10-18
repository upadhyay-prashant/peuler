#include<iostream>
using namespace std;
#include<stdio.h>
int main(){
    int sum[50];
    for(int i=0;i<50;i++)
        sum[i]=0;
    for(int i=0;i<100;i++){
        for(int j=0;j<50;j++){
            char ch=getchar_unlocked();
            ch=ch-'0';
            sum[j]+=ch;
        }
        getchar_unlocked();
    }
    int temp=0;
    for(int i=49;i>0;i--){
        if(sum[i]>10){
            temp=sum[i]/10;
            sum[i]=sum[i]%10;
            sum[i-1]+=temp;
        }
    }
    for(int i=0;i<50;i++)
        cout<<sum[i];
    return 0;
}
