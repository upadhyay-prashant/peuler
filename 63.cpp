#include<iostream>
using namespace std;
void print(int a[],int dig);
void mul(int a[],int &digits,int num);
int check(int num){
    int a[100];
    for(int i=0;i<100;i++)
        a[i]=0;
    a[0]=num;
    int digits=0;
    int count=1;
    while(digits+1 ==count){
        mul(a,digits,num);
        count++;
        print(a,digits);
    }
    return digits+1;
}
void print(int a[],int dig){
    cout<<" ";
    for(int i=dig;i>=0;i--)
        cout<<a[i];
}
void mul(int a[],int &digits,int num){
    int carry=0;
    for(int i=0;i<=digits || carry>0; i++){
        a[i]=a[i]*num+carry;
        carry=a[i]/10;
        a[i]=a[i]%10;
        if(digits<i)
            digits=i;
    }
}

int main(){
    int sum=0;
    for(int i=1;i<10;i++){
        int temp=check(i);
        cout<<"  ||||||"<<i<<" ="<<temp<<"\n";
        sum+=temp;
    }
    cout<<sum;
    return 0;
}
