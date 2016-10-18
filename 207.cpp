#include<iostream>
using namespace std;
bool calc(long long num){
	int count=9;
	while(count!=0){
		if(num%10!=count)
			return false;
		num=num/100;
		count--;
	}
	return true;
}
int main(){
	long long num=100000003;
	bool check=false;
	int temp=4;
	while(!check){
		num+=temp;
		long long square=num*num;
		check=calc(square);
		if(temp==4)
			temp=6;
		else
			temp=4;
		if(check)
			cout<<"\n the number is "<<square<<"\n";
	}
	num=num*10;
	cout<<num;
}