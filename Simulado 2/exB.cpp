#include < iostream >
#include<bits/stdc++.h>
#include < map >
#include < vector >
typedef long long int lli;
using namespace std;

vector < pair < lli, lli > > v;
int main() {

  map < lli, lli > second;

  map < lli, lli > frst;
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {

    lli a;
    cin >> a;
    v.push_back(make_pair(a, i));
  }
  lli ans = 0;
  for (int i = 0; i < n; i++) {

    lli temp = v[i].first;

    if ((v[i].first / (k * k)) * (k * k) == v[i].first && i >= 2)
    {

      ans += second[v[i].first / k];

    }

    if ((v[i].first / k) * k == v[i].first && i >= 1)
    {

      second[v[i].first] += frst[v[i].first / k];
    }

    frst[v[i].first]++;

  }
  cout << ans << endl;
  return 0;
}
