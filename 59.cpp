#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int arr[10000];
    for(int i=0;i<10000;i++)
        arr[i]=0;
    char ch='\0';
    int n=0;
    int count=0;
    while(ch=getchar_unlocked()){
        if(ch==-1){
            arr[count]=n;
            count++;
            break;
        }
        if(ch==','){
            arr[count]=n;
            n=0;
            count++;
            continue;
        }
        n=n*10 + ch-'0';
    }
    int a[100];
    for(int i=0;i<n;i++){
        a[i]=0;
    }
    for(int i=0;i<count;i++){
        a[arr[i]]++;
    }
    for(int i=0;i<100;i++){
        cout<<"\n "<<i<<" ==  "<<a[i];
    }

}
