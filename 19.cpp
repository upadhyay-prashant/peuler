#include<iostream>
using namespace std;
int main(){
    int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int mmm=0;
    for(int i=0;i<12;i++)
        mmm+=days[i];
    mmm++;
    mmm=mmm%7;
    int year=1901;
    int count=0;
    for(;year<=2000;year++){
        for(int i=0;i<12;i++){
            if((mmm+1)%7==0)
                count++;
            mmm=mmm+days[i];
            if(i==1 && ((year%4==0 && year%100!=0)||(year%400==0)))
                mmm++;
        }
    }
    cout<<" count is "<<count;
    return 0;
}
