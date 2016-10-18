#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    char ch='\0';
    int arr[1000];
    int ind=0;
    while(ch=getchar_unlocked()){
        if(!(ch>='0')||!(ch<='9')){
            if(ch=='\n')
                continue;
            else
                break;
        }
        arr[ind++]=ch-'0';
    }
    long long temp=1,max=0,temp1=0,cont=0;
    for(int i=0;i<ind;i++)
    {
        cout<<"\narr["<<i<<"] = "<<arr[i]<<" count is "<<cont;
        if(arr[i]!=0){
            cont++;
            if(cont>13)
                temp1=arr[i-13];
            else
                temp1=1;
            temp=temp/temp1;
            temp=temp*arr[i];
            cout<<" temp1 is "<<temp1<<" and prod is "<<temp;
            if(max<temp){
                max=temp;
                cout<<"****  max has become "<<max;
            }
        }
        else{
            cont=0;
            temp=1;
        }
        
    }
    return 0;
}
