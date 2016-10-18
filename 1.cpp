#include<iostream>
using namespace std;
int main(){
    int a[1000];
    for(int i=0;i<1000;i++)
        a[i]=0;
    for(int i=3;i<1000;i=i+3)
        a[i]=1;
    for(int i=5;i<1000;i=i+5)
        a[i]=1;
    int sum=0;
    for(int i=0;i<1000;i=i+1)
        if(a[i]==1)
            sum+=i;
    cout<<sum;

    return 0;
}
