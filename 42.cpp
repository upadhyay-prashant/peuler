#include<iostream>
#include<map>
#include<stdio.h>
using namespace std;
int main(){
    std::map<int,int> map;
    int sum=0;
    for(int i=1;i<=20;i++)
    {
        sum+=i;
        map[sum]=1;
    }
    char ch='\0';
    sum=0;
    int count=0;
    while(ch=getchar_unlocked()){
        if(ch>='A' && ch<='Z'){
            sum=sum+ch-'A'+1;
        }
        else if(ch==13){
            cout<<"\nsum is "<<sum;
            if(map.find(sum)!=map.end())
                count++;
            sum=0;
        }
        else{
            if(ch==-1)
                break;
            continue;
        }
    }
    cout<<"count is "<<count;

    return 0;
}
