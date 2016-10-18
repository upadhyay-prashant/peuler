#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    long long sum=0;
    char ch='\0';
    int line=1;
    int temp=0;
    while(ch=getchar_unlocked()){
        if(ch=='\n'){
            sum=sum+temp*line;
            cout<<"\nsum is "<<sum;
            line++;
            temp=0;
        }
        else if(ch>='A' && ch<='Z'){
            cout<<"\n ch is "<<ch;
            temp+=ch-'A'+1;
            cout<<"\t temp is "<<temp;
        }
        else if(ch==-1)
            return 0;
    }
    cout<<"\nsum is "<<sum;
    return 0;
}
