#include<iostream>
using namespace std;
int main(){
    int len=1000000;
    int a[1000000];
    for(int i=0;i<len;i++){
        a[i]=0;
    }
    for(int i=2;i<len;i++){
        int temp=2*i;
        while(temp<len && a[i]==0){
            a[temp]=1;
            temp=temp+i;
        }
    }
    int squares[1000];
    for(int i=0;i<1000;i++)
        squares[i]=(i)*(i);
    for(int i=4;i<len;i++){
        if(a[i]!=0 && i&1){
            int temp=0;
            while(i-2*squares[temp]>0 && a[i-2*squares[temp]]!=0){
                temp=temp+1;
            }
            if(a[i-2*squares[temp]]!=0){
                cout<<"thats the number i want "<<i;
                break;
            }
        }
    }
    return 0;
}
