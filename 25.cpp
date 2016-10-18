#include<iostream>
using namespace std;
bool foo(int a[]){
    if(a[999]!=0)
        return true;
    return false;
}
void copy(int a[],int b[]){
    for(int i=0;i<1001;i++){
        a[i]=b[i];
    }
}
void add(int a[],int b[],int c[]){
    for(int i=0;i<1001;i++){
        a[i]=b[i]+c[i];
    }
}
void settle(int a[]){
    for(int i=0;i<1001;i++){
        if(a[i]>=10){
            int temp=a[i]/10;
            a[i]=a[i]%10;
            a[i+1]+=temp;
        }
    }
}
int main(){
    int a[1001];
    int count=0;
    int b[1001];
    int c[1001];
    int temp[1001];
    for(int i=0;i<1001;i++){
        a[i]=0;
        b[i]=0;
        c[i]=0;
        temp[i]=0;
    }
    b[0]=1;
    c[0]=1;
    while(!foo(a)){
        if(count==0){
            add(a,b,temp);
            count++;
        }
        else if(count==1){
            count++;
        }
        else{
            add(a,b,c);
            settle(a);
            count++;
            copy(temp,c);
            copy(c,a);
            copy(b,temp);
        }
        cout<<endl;
        for(int i=1000;i>=0;i--){
            if(a[i]!=0)
                cout<<a[i];
        }
    }
    cout<<count;
    return 0;
}
