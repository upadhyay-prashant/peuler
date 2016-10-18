#include<iostream>
#include<vector>
using namespace std;
int main(){
    int len=1000000;
    int a[len];
    for(int i=2;i<len;i++)
        a[i]=0;
    for(int i=2;i<len;i++){
        int temp=2*i;
        while(temp<len)
        {
            a[temp]=1;
            temp+=i;
        }
    }
    std::vector<int> prime;
    int max=0;
    int num=0;
    for(int i=2;i<len;i++)
        if(a[i]==0)
            prime.push_back(i);
    for(int i=0; i<prime.size();i++){
        int sum=0;
        int count=0;
        for(int j=i;j<prime.size();j++){
            sum=sum+prime[j];
            count++;
            if(sum>len)
                break;
            if(a[sum]==0 && count>max){
                num=sum;
                max=count;
                cout<<"number updated to "<<sum<<" with nums"<<count<<endl;
            }
        }
    }

}
