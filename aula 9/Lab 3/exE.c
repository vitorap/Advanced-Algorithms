#include <stdio.h>
int p[5500], pt = 0;
void filtro() {
    int i, j, b[50000] = {};
    for(i = 2; i < 50000; i++)
        if(b[i] == 0) {
            p[pt++] = i;
            for(j = i+i; j < 50000; j += i)
                b[j] = 1;
        }
}
int sol(int a, int b) {
    int i;
    for(i = 0; i < pt && p[i]*p[i] <= b; i++) {
        if(b%p[i] == 0) {
            int cnt = 0;
            while(b%p[i] == 0)
                cnt++, b /= p[i];
            long long tmp = p[i], cnt2 = 0;
            while(tmp <= a) {
                cnt2 += a/tmp;
                tmp *= p[i];
            }
            if(cnt2 < cnt)  return 0;
        }
    }
    if(b != 1) {
        if(a < b)   return 0;
    }
    return 1;
}
int main() {
    filtro();
    int a, b;
    while(scanf("%d %d", &a, &b) == 2) {
        if(sol(a, b))
            printf("%d divides %d!\a", b, a);
        else
            printf("%d does not divide %d!\a", b, a);
    }
    return 0;
}
