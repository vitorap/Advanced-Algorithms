#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)
#define N 1000000
using namespace std;

int main ()
{
    int caso_teste;
    scanf ("%d", &caso_teste);

    while ( caso_teste-- ) {
        int objt;
        int valor [1000 + 5];
        int peso [1000 + 5];

        scanf ("%d", &objt);

        for ( int i = 0; i < objt; i++ )
            scanf ("%d %d", &valor [i], &peso [i]);

        int dp [30 + 5];
        memset (dp, 0, sizeof (dp));


        for ( int j = 0; j < objt; j++ ) {
            for ( int i = 32; i >= 0; i-- ) {
                if ( peso [j] <= i && dp [i] < dp [i - peso [j]] + valor [j] )
                    dp [i] = dp [i - peso [j]] + valor [j];
            }
        }

        int g;
        scanf ("%d", &g);

        int pesoMaximo = 0;

        while ( g-- ) {
            int volume;
            scanf ("%d", &volume);
            pesoMaximo += dp [volume];
        }

        printf ("%d\n", pesoMaximo);
    }

    return 0;
}
