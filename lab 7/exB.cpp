#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
int n,j,soma[maxn];
int main(){
    while(~scanf("%d %d",&n,&j)){
        int Min = INT_MAX,idx = -1;
        for(int i = 1; i <= n; ++i){
            scanf("%d",soma+i);
            soma[i] += soma[i-1];
            if(i >= j && soma[i] - soma[i-j] < Min){
                Min = soma[i] - soma[i-j];
                idx = i - j + 1;
            }
        }
        printf("%d\n",idx);
    }
    return 0;
}
