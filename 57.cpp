#include<iostream>
using namespace std;
int precision=400;
void print_fraction(int nr[],int dn[],int digits){
    cout<<"\n digits="<<digits<<"\t\t";
    for(int i=digits;i>=0;i--)
        cout<<nr[i];
    cout<<"      /     ";
    for(int i=digits;i>=0;i--)
        cout<<dn[i];
}
void calc(int dn[],int nr[],int &digits){
    int carry=0;
    int i;
    for(i=0;i<=digits || carry!=0;i++){
        dn[i]=dn[i]*2+carry;
        carry=dn[i]/10;
        dn[i]=dn[i]%10;
    }
    //carry=0;
    digits=i-1;
    for(i=0;i<=digits || carry!=0;i++){
        dn[i]=dn[i]+nr[i]+carry;
        carry=dn[i]/10;
        dn[i]=dn[i]%10;
    }
    digits=i-1;
}
bool isBig(int temp[],int dn[],int nr[],int digits){
    int i;
    bool check=false;
    int carry=0;
    for(i=0;i<=digits || carry!=0;i++){
        temp[i]=dn[i]+nr[i]+carry;
        carry=temp[i]/10;
        temp[i]=temp[i]%10;
        if(i>digits)
            check=true;
        //cout<<"nr=["<<i<<"]="<<nr[i]<<" dn[i]="<<dn[i]<<" temp[i]"<<temp[i];
    }
    cout<<" i is "<<i<<" digits is "<<digits;
    return check;
}
int main(){
    int *nr=new int[precision];
    int *dn=new int[precision];
    int *temp=new int[precision];
    for(int i=0;i<precision;i++){
        nr[i]=0;
        dn[i]=0;
    }
    nr[0]=1;
    dn[0]=2;
    int digits=0;
    int count=0;
    for(int i=0;i<1000;i++){
        for(int j=0;j<precision;j++){
            temp[j]=dn[j];
        }
        calc(dn,nr,digits);
        for(int j=0;j<precision;j++){
            nr[j]=temp[j];
        }
        print_fraction(nr,dn,digits);
        if(isBig(temp,nr,dn,digits)){
            count++;
        }
    }
    cout<<"\ncount is "<<count;
}
