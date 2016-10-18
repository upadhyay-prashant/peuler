#include<iostream>
using namespace std;
int main(){
    int len=1000000000;
    int *a=new int[len];
    for(int i=0;i<len;i++)
        a[i]=0;
    for(int i=2;i<len;i++){
        int temp=i*2;
        if(a[i]==0){
            while(temp<len){
                a[temp]=1;
                temp+=i;
            }
        }
    }
    bool check=true;
    int count_prime=0;
    int total=0;
    int count=1;
    int size=1;
    while(check){
        for(int i=0;i<4;i++){
            count=count+size+1;
            cout<<"count is "<<count;
            if(a[count]==0)
                count_prime++;
            total++;
        }
        size+=2;
        float ratio=(float)count_prime/(float)total;
        if(ratio<0.10)
            check=false;
        cout<<"\n for size = "<<size<<"  ratio = "<<ratio;
    }
    return 0;
}
