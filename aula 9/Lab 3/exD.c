#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long ll;

ll gcd(ll i,ll j){
    return j==0?i:gcd(j,i%j);
}

ll lcm(ll i,ll j){
    return i/gcd(i,j)*j;
}

int main(){
    ll n,i,j,p,q;
    while(scanf("%lld%lld%lld%lld%lld",&n,&i,&j,&p,&q)!=EOF)  {
        ll sum=0;
        sum=(n/i)*p+(n/j)*q-min(p,q)*(n/lcm(i,j));
        printf("%I64d\n",sum);
    }
    return 0;
}
