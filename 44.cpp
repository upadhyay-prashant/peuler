#include<iostream>
#include<map>
using namespace std;
std::map<long long,long long> a;
bool isPentagon(long long n){
    bool result=false;
    long long check=1+24*n;
    if(a[check]%6==5)
        result=true;
    if (result ==false)
        return false;
    cout<<"\n the question asked is "<<n<<" and answer is "<<(a[check]+1)/6;
    return result;
}
int main(){
    for(long long i=1;i<1000000;i++){
        long long sq=i*i;
        a[sq]=i;
        }
    std::map<long long,long long> pent;
    int count=1;
    bool check=true;
    while(check){
        long long num=count*(3*count-1)/2;
        pent[num]=count;
        std::map<long long,long long>::iterator recent=pent.end();
        recent--;
        cout<<"\n checking for count="<<count<<" num="<<num;
        for(std::map<long long,long long>::iterator it=pent.begin();it!=recent;it++){
            long long n1=it->first;
            if(pent.find(num-n1)!=pent.end() && isPentagon(num+n1)){
                cout<<"\n+++ num="<<num<<"  n1="<<n1<<" num-n1="<<num-n1;
//cout<<"\n"<<count<<" "<<it->second<<" ans is "<<pent.find(num-n1)->second;
                check=false;
                break;
            }
        }
        count++;
    }
    return 0;
}
       
