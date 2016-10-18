#include<iostream>
#include<vector>
#include<set>
using namespace std;
bool check(int fac,int prod){
    int arr[10];
    for(int i=0;i<10;i++){
        arr[i]=0;
    }
    int next=prod/fac;
    int temp=0;
    while(next>0){
        temp=next%10;
        next=next/10;
        arr[temp]++;
    }
    while(fac>0){
        temp=fac%10;
        fac=fac/10;
        arr[temp]++;
    }
    while(prod>0){
        temp=prod%10;
        prod=prod/10;
        arr[temp]++;
    }
    for(int i=1;i<10;i++){
        if(arr[i]!=1)
            return false;
    }
    if(arr[0]!=0)
        return false;
    return true;
}
int main(){
    std::set<int> prod_vec;
    std::vector<int> factors[100000];
    for(int i=2;i<100000;i++){
        int temp=2*i;
        while(temp<100000){
            factors[temp].push_back(i);
            temp=temp+i;
        }
    }
    for(int i=4;i<100000;i++){
        for(int j=0;j<factors[i].size();j++){
            //cout<<"\n going to check "<<i<<" with factor"<<(factors[i])[j];
            if(check((factors[i])[j],i)){
                int temp=(factors[i])[j];
                cout<<"\nfound  "<<i<<" with "<<temp<<" and "<<i/temp;
                if(prod_vec.find(i)==prod_vec.end())
                    prod_vec.insert(i);
            }
        }
    }
    int sum=0;
    for(std::set<int>::iterator it=prod_vec.begin();it!=prod_vec.end();it++){
        cout<<"\nnumber is "<<*it;
        sum+=*it;
    }
    cout<<"\nsum is "<<sum;
    return 0;

}
