#include<iostream>
using namespace std;
int findPower(int n)
{
    return n*n*n*n*n;
}
bool check(int n){
    int temp=n;
    int sum=0;
    while(temp>0){
        sum+=findPower(temp%10);
        temp=temp/10;
    }
    if(sum==n)
        return true;
    return false;
}
int main(){
    int i=2;
    int sum=0;
    for(;i<10000000;i++){
        if(check(i)){
            cout<<"\n  num is "<<i;
            sum+=i;
        }
    }
    cout<<" sum is "<<sum;
}
