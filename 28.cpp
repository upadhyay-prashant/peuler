#include<iostream>
using namespace std;
int main(){
    int i=3;
    int sum=1;
    int last=1;
    for(;i<1002;i=i+2){
        sum=sum+10*(i-1)+last*4;
        last=last+(i-1)*4;
        cout<<"\nsum is "<<sum<<" last is "<<last;
    }
    cout<<" sum is "<<sum;
}
