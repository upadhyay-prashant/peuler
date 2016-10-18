#include<iostream>
using namespace std;
int main(){
    int coin=201;
    int arr[]={0,1,2,5,10,20,50,100,200};
    int ans[9][coin];
    for(int i=0;i<9;i++)
        for(int j=0;j<coin;j++)
            ans[i][j]=0;
    for(int i=0;i<9;i++)
        ans[i][0]=1;
    for(int i=1;i<9;i++){
        for(int j=1;j<coin;j++){
            if(i==1)
                ans[i][j]=1;
            else{
                int den=arr[i];
                int temp=j;
                ans[i][j]=ans[i-1][j];
                while(temp>=den){
                    temp=temp-den;
                    ans[i][j]+=ans[i-1][temp];
                }
            }
        }
    }
 /*   for(int i=1;i<9;i++){
        cout<<endl;
        for(int j=1;j<coin;j++)
            cout<<" "<<ans[i][j];
    }*/
    return 0;
}
