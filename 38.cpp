#include<iostream>
using namespace std;


bool check(int i){
    int a[9];
    int count=0;
    int num=0;
    for(int j=1;j<10;j++)
        num=num|1<<(j-1);
    for(int j=1;count<9;j++){
        int temp=i*j;
        int h1=0,count_cache=count;
        while(temp>0){
            h1=h1*10+temp%10;
            a[count++]=temp%10;
            temp=temp/10;
            if(count==9 && temp!=0)
                return false;
        }
        count=count_cache;
        while(h1>0){
            a[count++]=h1%10;
            h1=h1/10;
        }
    }

    int temp=0;
    for(int j=0;j<9;j++){
        temp=temp|1<<(a[j]-1);
    }
    if(num==temp){
        for(int j=0;j<9;j++)
            cout<<a[j];
        cout<<endl;
    }
    return false;
}
int main(){
    for(int i=2;i<100000;i++){
        check(i);
    }
    return 0;
}
