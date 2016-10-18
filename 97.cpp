#include<iostream>
using namespace std;
int main(){
	long long temp=2;
	long long num=10000000000;
	for(int i=2;i<=7830457;i++){
		temp=temp*2;
		if(temp>num)
			temp=temp%num;
	}
	temp=temp*28433;
	temp=temp%num;
	temp=temp+1;
	cout<<temp;
	return 0;
}