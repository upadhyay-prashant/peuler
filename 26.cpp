#include<iostream>
#include<map>
using namespace std;
int findCount(int num){
    std::map<int,int> map;
    int count=0;
    int temp=10;
    while(true){
        int rem=temp%num;
        if(rem==0)
            return 0;
        if(map.find(rem)!=map.end())
        {
            count=count-map[rem];
            break;
        }
        map[rem]=count;
        count++;
        temp=rem*10;
        
    }
    return count;
}
int main(){
    int d=1000;
    int count_max=0;
    int max=0;
    for(int i=2;i<d;i++){
        int temp=findCount(i);
        cout<<"\n for i= "<<i<<" count= "<<temp;
        if(temp && temp>count_max){
            count_max=temp;
            max=i;
        }
    }
    cout<<"\n total recurring such numbers are "<<max<<"   "<<count_max;
    return 0;
}
