#include <bits/stdc++.h>

#define MAXN 100005
#define ll long long
#define pll pair<ll, ll>

using namespace std;

ll a[MAXN];
pll b[MAXN];
ll n;
ll s;

ll getval(ll p) {
    for (ll i = 1; i <= n; i++) {
        b[i].second = i;
        b[i].first = p * i + a[i];
    }
    sort(b + 1, b + n + 1);
    ll res = 0;
    for (ll i = 1; i <= p; i++) {
        res += b[i].first;
    }
    return res;
}

ll busca_binaria(ll l, ll r) {
    ll mid = l + r >> 1;
    ll res = mid;
    while (l <= r) {
        mid = l + r >> 1;
        if (s >= getval(mid)) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return res;
}

int main() {
    cin >> n >> s;
    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    ll p = busca_binaria(0, n);
    printf("%lld %lld\n", p, getval(p));
}
