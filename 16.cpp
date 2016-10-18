#include<iostream>
using namespace std;
int settle(int a[],int n){
    int i=0;
    while(i<n){
        int temp=a[i]/10;
        a[i]=a[i]%10;
        a[i+1]+=temp;
        i++;
    }
    cout<<"  i = "<<i<<" n is "<<n<<"  a[i]="<<a[i];
    if(a[i]!=0)
        return i+1;
    return n;
}
void multiply(int a[],int n){
    for(int i=0;i<n;i++)
        a[i]*=2;
}
int main(){
    int a[1000];
    for(int i=0;i<1000;i++)
        a[i]=0;
    a[0]=2;
    int count=1;
    for(int i=1;i<1000;i++){
        multiply(a,count);
        count=settle(a,count);
        cout<<" count = "<<count<<"  ";
        for(int j=count-1;j>=0;j--)
            cout<<a[j];
        cout<<endl;
    }
    int sum=0;
    for(int i=count-1;i>=0;i--)
        sum+=a[i];
    cout<<"\nsum is "<<sum;
}
