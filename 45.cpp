#include<iostream>
#include<map>
using namespace std;
int main(){
    std::map<long long,long long> tr;
    std::map<long long,long long> pe;
    std::map<long long,long long> he;
    long long count=1,terms=0;
    while(terms<3){
        long long sum1=count*(count+1)/2;
        long long sum2=count*(3*count-1)/2;
        long long sum3=count*(2*count-1);
        tr[sum1]=count;
        pe[sum2]=count;
        he[sum3]=count;
        if(pe.find(sum1)!=pe.end() && he.find(sum1)!=he.end())
        {
            cout<<count<<" "<<pe[sum1]<<" "<<he[sum1]<<" sum="<<sum1<<endl;
            terms++;
        }
        count++;
    }
    return 0;
}
