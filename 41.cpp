#include<iostream>
using namespace std;
bool check(int a){
    int temp=a;
    bool arr[10];
    for(int i=0;i<8;i++)
        arr[i]=false;
    int count=0;
    while(temp>0){
        arr[temp%10]=true;
        temp=temp/10;
        count++;
    }
    for(int i=1;i<count+1;i++)
        if(arr[i]==false)
            return false;
    return true;
}
int main(){
    int len=10000000;
    int *a=new int[len];
    for(int i=2;i<len;i++)
        a[i]=0;
    for(int i=2;i<len;i++){
        int temp=2*i;
        while(temp<len)
        {
            a[temp]=1;
            temp+=i;
        }
    }
    cout<<"sieve done";
    for(int i=11;i<len;i++){
        if(a[i]==0)
        {
            if(check(i)==true)
                cout<<" the number is"<< i;
        }
    }
    return 0;
}
