#include<iostream>
using namespace std;
int main(){
    int i=1,j=1,num=0;
    int sum=0;
    while(num<4000000)
    {
        num=i+j;
        i=j;
        j=num;
        if(num%2==0)
            sum+=num;
        cout<<sum<<endl;
    }
}
