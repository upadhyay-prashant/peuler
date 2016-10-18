#include<iostream>
using namespace std;
void multiply(int a[],int n){
    for(int i=0;i<10;i++){
        a[i]*=n;
    }
}
void settle(int a[]){
    for(int i=0;i<10;i++){
        if(a[i]>=10){
            int temp=a[i]/10;
            a[i]=a[i]%10;
            if (i!=9)
                a[i+1]+=temp;
        }
    }
}
void add(int a[],int b[]){
    for(int i=0;i<10;i++){
        a[i]+=b[i];
    }
}
int main(){
    int a[10];
    int sum[10];
    for(int j=0;j<10;j++)
        sum[j]=0;
    for(int i=1;i<1001;i++){
        for(int j=0;j<10;j++)
            a[j]=0;
        a[0]=i;
        for(int j=1;j<i;j++){
            multiply(a,i);
            settle(a);
        }
        for(int j=9;j>=0;j--){
            cout<<a[j];
        }
        cout<<"\t";
        add(sum,a);
        settle(sum);
        for(int j=9;j>=0;j--){
            cout<<sum[j];
        }
        cout<<endl;
    }
}
