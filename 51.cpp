#include<iostream>
#include<stdio.h>
using namespace std;
int const len=10000000;
int a[len];
bool is8Prime(int num){
    int count[10];
    for(int i=0;i<10;i++)
        count[i]=0;
    int temp=num;
    while(temp){
        count[temp%10]++;
        temp=temp/10;
    }
    for(int i=0;i<3;i++){
        int pr=0;
        if(count[i]>1){
            temp=num;
            int factor=1;
            while(temp){
                if(temp%10==i)
                    pr+=1*factor;
                factor=factor*10;
                temp=temp/10;
            }
            temp=num-i*pr;
            int pr_count=0;
            char msg[1000];
            char *ch;
            ch=msg;
            for(int j=i;j<10;j++){
                if(a[temp+pr*j]==0){
                    pr_count++;
                    ch+=sprintf(ch," a[%d]=%d ",temp+pr*j,a[temp+pr*j]);
                }
            }
            sprintf(ch,"   %d",temp);
            if(pr_count==8){
                cout<<"\n"<<msg;
                return true;
            }
        }
    }
    return false;
}
int main(){
    for(int i=0;i<len;i++)
        a[i]=0;
    for(int i=2;i<len;i++)
    {
        int temp=i*2;
        if(a[i]==0)
            while(temp<len){
                a[temp]=1;
                temp=temp+i;
            }
    }
    for(int i=56000;i<len;i++){
        if(a[i]==0){
            if(is8Prime(i))
                cout<<" the number is "<<i;
        }
    }
    return 0;
}
