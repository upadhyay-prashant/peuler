#include<iostream>
using namespace std;
int main(){
    int sum=0;
    for(int i=1;i<10;i++){
        for(int j=1;j<10;j++){
            sum=10*i+j;
            for(int k=2;k<10;k++){
                sum=sum*k;
                int temp=sum;
                int temp2=temp;
                int temp3=0;
                while(temp>0){
                    temp=temp/10;
                    temp3=temp%10;


                }
            }
        }
    }
    return 0;
}
