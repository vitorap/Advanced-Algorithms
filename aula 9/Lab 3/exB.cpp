#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ll long long
#define maxL (10000000>>5)+1
#define GET(x) (mark[x>>5]>>(x&31)&1)
#define SET(x) (mark[x>>5] |= 1<<(x&31))
int mark[maxL];
void filtro() {
    register int i, j, k;
    SET(1);
    int a = 10000000;
    for(i = 2; i <= a; i++) {
        if(!GET(i)) {
            for(k = a/i, j = i*k; k >= i; k--, j -= i)
                SET(j);
        }
    }
}
main() {
    filtro();
    int t;
    ll a, b;
    scanf("%d", &t);
    while(t--) {
        scanf("%lld", &a), b = sqrt(a);
        if(b*b != a || GET(b))
            puts("NO");
        else    puts("YES");
    }
    return 0;
}
