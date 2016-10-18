#include<iostream>
using namespace std;
int hcf(int a,int b){
    int big,small,t;
    if(a>b){
        big=a;
        small=b;
    }
    else{
        big=b;
        small=a;
    }
    bool temp=true;
    while(big!=1 || temp!=false){
        t=big%small;
        if(t==0)
            break;
        big=small;
        small=t;
    }
    return small;
}
int calc(int a,int b){
    int prod=a*b;
    int temp=hcf(a,b);
    int res=prod/temp;
    return res;
}
int main(){
    int lcm=2;
    for(int i=3;i<21;i++){
        lcm=calc(lcm,i);
    }
    cout<<lcm;
}
