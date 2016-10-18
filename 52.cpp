#include<iostream>
using namespace std;
bool check(int n){
    bool a[10];
    for(int i=0;i<10;i++)
        a[i]=false;
    int temp=n;
    int temp1=0;
    while(temp>0){
        a[temp%10]=true;
        temp1=temp;
        temp=temp/10;
    }
    if(temp1!=1)
        return false;
    for(int i=2;i<7;i++){
        temp1=i*n;
        bool *ab=new bool[10];
        while(temp1>0){
            ab[temp1%10]=true;
            temp1=temp1/10;
        }
        for(int i=0;i<10;i++){
            if(a[i]!=ab[i])
                return false;
        }
        delete [] ab;
    }
    return true;
}
int main(){
    for(int i=10;i<1000000;i++)
        if(check(i))
            cout<<"the number is "<<i;
    return 0;
}
