#include<iostream>
#include<stdio.h>
using namespace std;
struct Card{
    int card_value;
    char suit;
};
void take_inp(Card &pl){
    char ch='\0';
    ch=getchar_unlocked();
    if(ch=='J')
        pl.card_value=11;
    else if(ch=='Q')
        pl.card_value=12;
    else if(ch=='K')
        pl.card_value=13;
    else if(ch=='A')
        pl.card_value=14;
    else if(ch=='T')
        pl.card_value=10;
    else
        pl.card_value=ch-'0';
    ch=getchar_unlocked();
    pl.suit=ch;
}
// 0=high card
// 1=one pair
// 2=two pairs
// 3=three of a kind
// 4=straight
// 5=flush
// 6=full house
// 7=four of a kind
// 8=straight flush
// 9=royal flush
class hand{
    public:
        int value;
        int a[5];
};
void input(hand &hhh,Card card[]){
    int a[15];
    for(int i=0;i<15;i++){
        a[i]=0;
    }
    bool flush=false;
    int count=0;
    char ch=card[0].suit;
    for(int i=0;i<5;i++){
        hhh.a[i]=card[i].card_value;
        a[card[i].card_value]++;
        if(card[i].suit==ch)
            count++;
    }
    if(count==5)
        flush=true;
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            if(hhh.a[i]>hhh.a[j]){
                int temp=hhh.a[i];
                hhh.a[i]=hhh.a[j];
                hhh.a[j]=temp;
            }
        }
    }
    int count_pair=0;
    bool triplet=false;
    bool quad=false;
    for(int i=0;i<15;i++){
        if(a[i]==2){
            count_pair++;
        }
        else if(a[i]==3)
            triplet=true;
        else if(a[i]==4)
            quad=true;
    }
    int val=0;
    if(count_pair==1 && triplet)
        val=6;
    else if(triplet)
        val=3;
    else if(quad)
        val=7;
    else if(count_pair>0)
        val=count_pair;
    if(val<5 && flush)
        val=5;
    //flush, straight, royal flush
    if(val==0 || val==5){
        bool check=true;
        for(int i=4;i>0;i--){
            if(hhh.a[i]-hhh.a[i-1]!=1)
                check=false;
        }
        if(check){
            if(flush){
                if(a[4]==14)
                    val=9;
                else
                    val=8;
            }
            else
                val=4;
        }
    }
    hhh.value=val;
}
int main(){
    Card pl1[5],pl2[5];
    int count=0;
    for(int j=0;j<1000;j++){
        for(int i=0;i<5;i++){
            take_inp(pl1[i]);
            getchar_unlocked();
        }
        for(int i=0;i<5;i++){
            take_inp(pl2[i]);
            getchar_unlocked();
        }
        hand h1,h2;
        input(h1,pl1);
        input(h2,pl2);
        for(int i=0;i<5;i++)
            cout<<h1.a[i]<<" ";
        for(int i=0;i<5;i++)
            cout<<h2.a[i]<<" ";
        cout<<"   for game "<<j<<" h1.value is "<<h1.value<<" h2.value is "<<h2.value;
        if(h1.value>h2.value){
            cout<<" so first win";
            count++;
        }
        else if(h1.value==h2.value){
            cout<<" so its a tie";
            for(int i=4;i>=0;i--){
                if(h1.a[i]>h2.a[i]){
                    cout<<"first win by high card";
                    count++;
                    break;
                }
                else{ 
                    cout<<"second win by high card";
                    break;
                }
            }
        }
        cout<<endl;
    }
    cout<<count<<endl;
    return 0;
}
