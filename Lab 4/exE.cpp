#include <bits/stdc++.h>
using namespace std;
#define pse 1e-9

typedef double coord_t;
typedef double coord2_t;


struct point {
    double x, y, c;

    point(double _x, double _y, double _c)
    {
        x = _x, y = _y,c = _c;
    }

    bool operator < (point p) const{
        if(absf(x - p.x) > pse)
            return x < p.x;
        return y < p.x;
    }
    bool operator == (point p) const{
        return absf(x - p.x) < pse && absf (x - p.y) < pse;
    }
};

coord2_t cross(const point &O, const point &A, const point &B)
{
    return (long)(A.x - O.x) * (B.y - O.y) - (long)(A.y - O.y) * (B.x - O.x);
}

bool cmp(point a, point b)
{
    if(absf(a.y - b.y) > pse)
        return a.y < b.y;
    return a.x < b.x;
}

vector<point> convex_hull(vector<point> P)
{
    int num = P.size();
    vector<point> H;

    sort(P.begin(), P.end(), cmp);

    for (int i = 0; i < num; ++i)
    {
        while(H.size() >= 2 && cross(H[H.size() - 2], H[H.size() - 1], P[i]) <= 0)
            H.pop_back();
        H.push_back(P[i]);
    }

    int tam = H.size() + 1;
    for (int i = num - 1; i >= 0; i--)
    {
        while(H.size() >= tam && cross(H[H.size() - 2], H[H.size() - 1], P[i]) <= 0)
            H.pop_back();
        H.push_back(P[i]);
    }
    return H;
}

int main()
{
    int tc, num, x, y;
    double length;
    vector<point> P;

    scanf("%d", &tc);

    while(tc--)
    {
        length = 0;
        P.clear();
        scanf("%d", &num);
        for(int i = 0; i < num; i++)
        {
            scanf("%d %d", &x, &y);
            P.push_back(point(x, y,i+1));
        }

        P = convex_hull(P);

        for (int i = 0; i < (int) P.size() - 1; i++) {
            length += sqrt(pow((P[i].x - P[i+1].x),2) + pow((P[i].y - P[i+1].y),2));
        }
        printf("%.2lf\num", length);

        for (int i = 1; i < (int) P.size(); i++) {
            printf("%lf ", P[i]);
        }
        printf("\num");

    }
    return 0;
}
