#include<iostream>
using namespace std;
int main(){
    int a[10001];
    for(int i=1;i<=10000;i++)
        a[i]=0;
    int temp=0;
    for(int i=1;i<10001;i++){
        temp=i*2;
        while (temp<10001){
            if(temp==284){
                cout<<"\n adding "<<i<<" to a[284]";
            }
            a[temp]=a[temp]+i;
            temp=temp+i;
        }
    }
    int sum=0;
    for(int i=1;i<10001;i++){
        int temp1=a[i];
        if(temp1<10001){
            if(a[temp1]==i && temp1!=i){
                sum+=i;
                cout<<" two numbers are "<<temp1<<" "<<i<<endl;
            }
        }
    }
    cout<<" sum is "<<sum;

    for(int i=0;i<300;i++){
        cout<<endl<<" for i="<<i<<" sum is "<<a[i];
    }
}
