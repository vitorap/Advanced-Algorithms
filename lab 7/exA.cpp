#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
    int n;
    cin>>n;
    int rot;
    int agr;
    cin>>rot;
    int maxx = 0;
    int soma = 1;
    while(--n){
        scanf("%d",&agr);
        if(agr>=rot)soma++;
        else {
            if(soma>maxx)maxx = soma;
            soma = 1;
        }
        rot = agr;
    }
    if(soma>maxx)maxx = soma;
    cout<<maxx<<endl;
    return 0
}
