#include<bits/stdc++.h>
using namespace std;
int main(){
  int caminho[490];
  int coin[5] = {50,25,10,5,1};
  memset(caminho,0,sizeof(caminho));
  caminho[0]=1; //not taking any coins also an option
  for(int j=0;j<5;j++){
    for(int i=1;i<7490;i++){
      if(i>=coin[j]){
        caminho[i]+=caminho[i-coin[j]]; // using dynamic approach
      }
    }
  }
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    int d;
    scanf("%d",&d);
    cout<<caminho[d]<<endl;
  }

}
