#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(a) cout << #a << " " << a << endl
using namespace std;
const int maxn = 1e3 + 10;
typedef long long ll;
ll gcd( ll p, ll q ) {
    if( p == 0 ) {
        return q;
    }
    if( q == 0 ) {
        return p;
    }
    return gcd( q, p%q );
}
int main(){
    std::ios::sync_with_stdio(false);
    ll esq, dir, a, b;

    while( cin >> esq >> dir >> a >> b ) {
        ll num = 0;
        vector<ll> e;
        for( ll i = 1; i * i <= b; i ++ ) {
            if( b % i == 0 ) {
                e.push_back(i);
                if( i != b/i ) {
                    e.push_back(b/i);
                }
            }
        }
        for( ll i = 0; i < e.size(); i ++ ) {
            for( ll j = 0; j < e.size(); j ++ ) {
                if( gcd( e[i], e[j] ) == a && e[i] * e[j] == a * b
                   && e[i] >= esq && e[i] <= dir && e[j] >= esq && e[j] <= dir ) {
                    num ++;
                }
            }
        }
        cout << num << endl;
    }
    return 0;
}
