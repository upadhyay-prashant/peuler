#include<iostream>
#include<map>
#include<stdio.h>
using namespace std;
int trig(int i){
    return i*(i-1)/2;
}
int quad(int i){
    return i*i;
}
int pent(int i){
    return i*(3*i-1)/2;
}
int hexa(int i){
    return i*(2*i-1);
}
int hepta(int i){
    return i*(5*i-3)/2;
}
int oct(int i){
    return i*(3*i-2);
}
typedef int ((*func)(int));
func func_arr[6]={trig,quad,pent,hexa,hepta,oct};

bool check1(std::map<int,int>* arr,
            std::map<int,int>::iterator it,int ind,
            std::map<int,int>::iterator it1){
    if(ind==5 && it->first!=it1->second ){
        return false;
    }
    int val=0;
    if(ind==-1){
        val=it->second;
    }
    else
        val=it1->second;
    ind=(ind+1)%6;
    std::map<int,int>::iterator it2=arr[ind].find(val);
    bool res=false;
    if(it2==arr[ind].end())
        return false;
    else
        res= check1(arr,it,ind,it2);
    if(res==true){
        printf("\t%d%d",it2->first,it2->second);
    }
    else printf("\t failed(%d%d)",it2->first,it2->second);
    return res;

}
void check(std::map<int,int> arr[]){
    std::map<int,int>::iterator it=arr[5].begin();
    for(;it!=arr[5].end();it++){
        printf("\n++++  checking %d->%d",it->first,it->second);
        if(check1(arr,it,-1,it)) return;
    }

}
int main(){
    std::map<int,int> my_map[6];
    int i=0;
    while(func_arr[0](i)<10000){
        i++;
        for(int j=0;j<6;j++)
        {
            int num=func_arr[j](i);
            if(num<10000 ){
                if(num>1000){
                    int ind=num/100;
                    int value=num%100;
                    my_map[j][ind]=value;
                }
            }
            else
                break;
        }
    }
    for(int i=0;i<6;i++)
    {
        printf("\n%d: ",i+1);
        for(std::map<int,int>::iterator it=my_map[i].begin();it!=my_map[i].end();it++)
            printf(" %d%d,",it->first,it->second);
    }

    check(my_map);
    return 0;
}
