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
            return n ;
        }
        else {
            return 0;
        }
    }
}
int max(int a,int b){
    if(a>b)
        return a;
    return b;
}
int main(){
    int len=100;
    int a[len][len];
    int count;
    for(int i=0;i<len;i++){
        count=0;
        for(int j=0;j<len;j++){
            if(j<(len-i)/2 || j>(len+i)/2)
                a[i][j]=0;
            else{
                a[i][j]=take_inp();
            }
        }
    }
    int sum[len][len];
    for(int i=0;i<len;i++){
        sum[0][i]=a[0][i];
    }
    for(int i=0;i<len;i++){
        cout<<endl;
        for(int j=0;j<len;j++)
            cout<<"\t"<<a[i][j];
    }
    for(int i=1;i<len;i++){
        for(int j=0;j<len;j++){
            if(a[i][j]!=0){
                int ind1=(len-i+1)/2+j-(len-i)/2;
                int ind2=(len-i-1)/2+j-(len-i)/2;
                sum[i][j]=a[i][j]+max(ind1>=0?sum[i-1][ind1]:0,ind2<len?sum[i-1][ind2]:0);
            }
            else
                sum[i][j]=0;
        }
    }
    int max=0;
    cout<<endl;
    for(int i=0;i<len;i++){
        cout<<"========";
        if(sum[len-1][i]>max){
            max=sum[len-1][i];
        }
    }
    for(int i=0;i<len;i++){
        cout<<endl;
        for(int j=0;j<len;j++)
            cout<<"\t"<<sum[i][j];
    }
    cout<<" sum is "<<max;
}
