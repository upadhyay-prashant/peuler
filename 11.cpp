#include<iostream>
#include<stdio.h>
using namespace std;
int take_inp(){
    int  n =0;
    char ch='\0';
    while (ch=getchar_unlocked()){
        if(ch>='0' && ch<='9'){
            n=(n<<3)+(n<<1)+(ch-'0');
        }
        else if(ch=='\n' || ch==' '){
            ////printf("\n++++  take_inp returning %d",n);
            return n ;
        }
        else {
            return 0;
        }
    }
}
int compute(int a[][20],int i,int j){
    int res=1;
    for(int k=0;k<4;k++){
        res=res*a[i+k][j+k];
    }
    return res;
}
int comp(int a[][20],int i,int j){
    int res=1;
    for(int k=0;k<4;k++){
        res=res*a[i+k][j-k];
    }
    return res;
}
int main(){
    int arr[20][20];
    char ch='\0';
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            arr[i][j]=take_inp();
        }
    }
    //left to right
    int max=1,prod=1,count=0,temp=1;
    for(int i=0;i<20;i++){
        prod=1;
        count=0;
     //   cout<<"\n$$$$ for i = "<<i;
        for(int j=0;j<20;j++){
            //cout<<"\n  arr["<<j<<"]= "<<arr[i][j]<<" count= "<<count<<" ";
            if(arr[i][j]!=0){
                count++;
                if(count>4){
                    temp=arr[i][j-4];
                }
                else
                    temp=1;
                prod=prod/temp;
                prod=prod*arr[i][j];
                if(prod>max)
                {
                    max=prod;
                    cout<<"\n ***** max has become "<<max;
                }
            }
            else{
                prod=1;
                count=0;
            }
        }
    }
    // top to bottom
    cout<<"\n************ top to bottom**************";
    for(int j=0;j<20;j++){
     //   cout<<"\n $$$ for  column "<<j;
        prod=1;
        count=0;
        for(int i=0;i<20;i++){
           // cout<<"\n  arr= "<<arr[i][j]<<" count= "<<count<<" ";
            if(arr[i][j]!=0){
                count++;
                if(count>4){
                    temp=arr[i-4][j];
                }
                else{
                    temp=1;
                }
                prod=prod/temp;
                prod=prod*arr[i][j];
                if(prod>max)
                {
                    max=prod;
                    cout<<"\n ***** max has become "<<max;
                }
            }
            else{
                prod=1;
                count=0;
            }
        }
    }
    //left to right diagonal
    cout<<"\n************ left to right diagonal**************";
    for(int i=0;i<=16;i++){
        for(int j=0;j<=16;j++){
           // cout<<"\n for i="<<i<<", j="<<j<<", arr="<<arr[i][j]<<",  prod= "<<prod;
            prod=compute(arr,i,j);
            if(prod>max){
                cout<<" ***** max has become  "<<max<<" i = "<<i<<" j="<<j;
                max=prod;
            }
        }
    }
    cout<<"\n************ right to left diagonal**************";
    for(int i=0;i<=16;i++){
        for(int j=3;j<20;j++){
            cout<<"\n for i="<<i<<", j="<<j<<", arr="<<arr[i][j]<<",  prod= "<<prod;
            prod=compute(arr,i,j);
            prod=comp(arr,i,j);
            if(prod>max)
            {
                max=prod;
                cout<<" ***** max has become  "<<max<<" i = "<<i<<" j="<<j;
            }
        }
    }
    return 0;
}
