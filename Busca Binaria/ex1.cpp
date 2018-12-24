#include <bits/stdc++.h>

using namespace std;

typedef vector<long long> vll;
typedef vector<vector<long long> > vvll;


long long solve(int campo, int restam, vvll &mem, const vll &dist) {
    if (campo == 0 && restam == 0)
        return 0;

    if (restam == 0 || campo == 0)
        return INT_MAX;

    if (mem[campo][restam] != -1)
        return mem[campo][restam];

    for (int prev = restam - 1; prev < campo; prev++) {
        long long resp = solve(prev, restam - 1, mem, dist);
        resp = max(resp, dist[campo] - dist[prev]);

        if (mem[campo][restam] == -1 || mem[campo][restam] > resp)
            mem[campo][restam] = resp;
    }

    return mem[campo][restam];
}

int main() {
    int n, k;
    while (cin >> n >> k) {
        n += 2;
        k += 1;

        vector<long long> dist(n);
        for (int i = 1; i < n; i++) {
            cin >> dist[i];
            dist[i] += dist[i - 1];
        }

        vvll mem(n, vll(k + 1, -1));

        cout << solve(n - 1, k, mem, dist) << "\n";
    }

    return 0;
}
