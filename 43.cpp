#include<iostream>
using namespace std;
long long find(long long num,int check){
    int ref=0;
    int a[7];
    int count=0;
    for(int i=0;i<4;i++)
        a[i]=0;
    long long temp=num;
    for(int i=0;i<10;i++){
        int temp=num%10;
        ref=ref|(1<<temp);
        num=num/10;
    }
    if(ref!=check)
        return 0;
    num=temp;
    while(num>1000){
        a[count++]=num%1000;
        num=num/10;
    }
    int div[]={17,13,11,7,5,3,2};
    for(int i=0;i<7;i++){
        if(a[i]%div[i]!=0)
            return 0;
    }
    return temp;
}
int main(){
    long long num=1000000000;
    int check=0;
    for(int i=0;i<10;i++)
        check=check|(1<<i);
    long long sum=0;
    while(num<10000000000){
        int temp=find(num,check);
        if(temp!=0)
        {   
            cout<<" number found is "<<num<<endl;
            sum=sum+temp;
            cout<<"sum is "<<sum;
        }
        num++;
    }
    cout<<"sum is "<<sum;
    return 0;
}
