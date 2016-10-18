#include<iostream>
using namespace std;
int cache[10000];
int precision=50;
void convert(int n,int num[],int &digits){
    int i=0;
    for(i=0;i<5 && n>0;i++){
        num[i]=n%10;
        n=n/10;
    }
    digits=i;
}
int convert_back(int num[],int digits){
    int i=0;
    for(int j=digits;j>=0;j--)
        i=i*10+num[j];
    return i;
}
void print(int n[],int digits){
    for(int i=digits;i>=0;i--){
        cout<<n[i];
    }
}
void add(int n1[],int n2[],int &digits){
    int carry=0;
    int i;
    for(i=0;i<=digits || carry!=0;i++){
        n2[i]=n1[i]+n2[i]+carry;
        carry=n2[i]/10;
        n2[i]=n2[i]%10;
    }
    digits=i-1;
}
int check_palindrome(int n[],int digits){
    for(int i=0;i<=digits/2;i++){
        if(n[i]!=n[digits-i])
            return 0;
    }
    return 1;
}
int find_lycheral(int num[],int digits,int count){
    if(count>50)
        return 0;
    count++;
    cout<<"|| number to be checked is ";
    print(num,digits);
    int *num_reverse=new int[precision];
    for(int i=0;i<precision;i++)
        num_reverse[i]=0;
    for(int i=0;i<=digits;i++){
        num_reverse[i]=num[digits-i];
    }
    if(digits<4)
    cout<<"||  cache is "<<cache[convert_back(num,digits)]<< " "<<cache[convert_back(num_reverse,digits)];
    if(digits<4 && (cache[convert_back(num,digits)]!=-1 )){
        cout<<" returning ";
        return cache[convert_back(num,digits)];
    }
    cout<<"|| reverse number is ";
    print(num_reverse,digits);
    add(num,num_reverse,digits);
    cout<<"|| sum is ";
    print(num_reverse,digits);
    int res=check_palindrome(num_reverse,digits);
    cout<<"|| is_palindrome "<<res;
    if(res==1)
        return 1;
    res=find_lycheral(num_reverse,digits,count);
    if(digits<4){
        cout<<" marking cache["<<convert_back(num_reverse,digits)<<"]="<<res;
        cache[convert_back(num_reverse,digits)]=res;
    }
//delete [] num_reverse;
    return res;
}
int main(){
    int len=10000;
    for(int i=0;i<10000;i++){
        cache[i]=-1;
    }
    int *num=new int[precision];
    for(int i=11;i<len;i++){
        for(int j=0;j<precision;j++){
            num[j]=0;
        }
        int digits=0;
        convert(i,num,digits);
        digits--;
        cache[i]=find_lycheral(num,digits,0);
        cout<<"\n***********************";
    }
    int count=0;
    cout<<"\n";
    for(int i=11;i<len;i++){
        if(cache[i]==0){
            count++;
            cout<<" "<<i;
        }
    }
    cout<<" "<<count;
    return 0;
}
