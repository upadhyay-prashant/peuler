#include<iostream>
using namespace std;
int sum(int a[]){
    int sum=0;
    for(int i=0;i<200;i++)
        sum+=a[i];
    return sum;
}
void settle(int a[]){
    for(int i=0;i<200;i++){
        if(a[i]>9){
            int temp=a[i]%10;
            a[i+1]+=a[i]/10;
            a[i]=temp;
        }
    }
}
void multiply(int a[],int num){
    for(int i=0;i<200;i++){
        a[i]=a[i]*num;
    }
}
int main(){
    int max=0;
    int a[200];
    for(int i=2;i<100;i++){
        for(int j=0;j<200;j++)
            a[j]=0;
        a[0]=i;
        for(int j=1;j<100;j++){
            multiply(a,i);
            settle(a);
            if(sum(a)>max){
                max=sum(a);
                cout<<"sum has been increased to "<<max<<" for i= "<<i<<" j="<<j<<endl;
            }
        }
    }
}
