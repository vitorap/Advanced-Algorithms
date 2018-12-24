#include <stdio.h>
#include <math.h>
#define eps 1e-15

int p, q, r, s, t, u;
double calc(double xn) {
    return p*exp(-xn) + q*sin(xn) + r*cos(xn) + s*tan(xn) + t*xn*xn + u;
}
double buscaBinaria() {
    double mx, a, b, m;
    int aux = 50;
    a = 0, b = 1;
    while(aux--) {
        m = (a+b)/2;
        mx = calc(m);
        if(fabs(mx) < eps)
            return m;
        if(mx > 0)  a = m;
        else        b = m;
    }
    return -1;
}
int main() {
    while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) == 6) {
        if(!p && !q && !r && !s && !t && !u) {
            puts("0.0000");
            continue;
        }
        double noSolution = buscaBinaria();
        if(noSolution == -1) {
            puts("No solution");
        } else
            printf("%.4lf\n", noSolution);
    }
    return 0;
}
