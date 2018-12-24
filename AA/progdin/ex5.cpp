#include <iostream>
using namespace std;
int main() {
    int n, i, j, a[100000], maxTam, size[100000];
    int caso = 0;
    bool End = false;
    while (cin >> a[0]) {
        if (a[0]==-1) break;
        if (End) cout << endl;
        End = true;
        n = 0;
        while (cin >> a[++n])
            if (a[n]==-1) break;
        maxTam = 0;
        for (i=0;i<n;i++) {
            size[i] = 1;
            for (j=i-1;j>=0;j--)
                if (a[i]<a[j] && size[j]+1>size[i])
                    size[i] = size[j] + 1;
            if (size[i]>maxTam) maxTam = size[i];
        }
        printf("Test #%d:\nmaximum possible interceptions: %d\n",++caso,maxTam);
    }
    return (0);
}
