#include<iostream>
using namespace std;
int main(){
    long long a[100][101];
    for(int i=0;i<100;i++)
        for(int j=0;j<101;j++)
            a[i][j]=0;
    a[0][0]=1;
    a[1][0]=1;
    a[1][1]=2;
    a[1][2]=1;
    int count=0;
    for(int i=2;i<100;i++)
        for(int j=0;j<i+2;j++){
            if(j!=0 && a[i-1][j-1]<0)
                a[i][j]=-1;
            else if(j!=0)
                a[i][j]=a[i-1][j]+a[i-1][j-1];
            else
                a[i][j]=1;
            if(a[i][j]>1000000 || a[i][j]<0)
                count++;
            cout<<i+1<<"C"<<j<<" ="<<a[i][j]<<endl;
        }
    cout<<"count is "<<count;

    return 0;
}
