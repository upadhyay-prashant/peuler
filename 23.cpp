#include<iostream>
#include<vector>
using namespace std;
bool check(int n,std::vector<int> vec){
    int first=0;
    int last=vec.size()-1;
    while(first<=last){
        if(vec[first]+vec[last]>n){
            last--;
        }
        else if(vec[first]+vec[last]<n)
        {
            first++;
        }
        else{
            return true;
        }
    }
    return false;
}
int main(){
    int len=28123;
    int a[len];
    for(int i=1;i<=len;i++)
        a[i]=0;
    int temp=0;
    for(int i=1;i<len;i++){
        temp=i*2;
        while (temp<len){
            a[temp]=a[temp]+i;
            temp=temp+i;
        }
    }
    int sum=0;
    std::vector<int> vec;
    for(int i=1;i<len;i++){
        int temp1=a[i];
        if(temp1>i){
            vec.push_back(i);
        }
    }
    cout<<"vector size is"<<vec.size();
    //for(int i=0;i<vec.size();i++){
    //    cout<<"\n\t "<<vec[i];
    //}
    for(int i=1;i<28123;i++){
        if(!check(i,vec))
        {
  //          cout<<"\nnum is "<<i;
            sum+=i;
        }
    }
    cout<<"\nsum is "<<sum;
    return 0;
}
