#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    int *a=new int[100000000];
    cout<<"check";
    for(int i=0;i<100000000;i++){
        a[i]=0;
    }
    for(int i=2;i<100000000;i++){
        int temp=2*i;
        while(temp<100000000){
            a[temp]++;
            temp=temp+i;
        }
    }
    for(int i=0;i<100000000;i++){
        cout<<"\n "<<i<<" ="<<a[i];
    }
    return 0;
    for(int i=1;i<50000;i++){
        int sum=(i*(i+1))/2;
        cout<<"\nsum is "<<sum<<" count is "<<a[sum]; 
        if(a[sum]>500)
        {
            cout<<"\n ans is "<<sum<<" i="<<i;
            break;
        }
    }
    return 0;
}
