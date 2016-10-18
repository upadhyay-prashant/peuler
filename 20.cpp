#include<iostream>
using namespace std;
int settle(int a[]){
    int i=0;
    bool check=true;
    while(i<200){
        int temp=a[i]/10;
        a[i]=a[i]%10;
        if(i<199) a[i+1]+=temp;
        i++;
    }
}
void multiply(int a[],int mul){
    for(int i=0;i<200;i++)
        a[i]*=mul;
}
int main(){
    int a[200];
    a[0]=1;
    for(int i=1;i<200;i++)
        a[i]=0;
    for(int i=2;i<101;i++)
    {
        multiply(a,i);
        settle(a);
    }
    int sum=0;
    for(int i=199;i>=0;i--)
        sum+=a[i];
    cout<<"\nsum is "<<sum;

    return 0;
}
