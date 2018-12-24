#include<bits/stdc++.h>

#define ll long long
using namespace std;

int main()
{
    double Rr,a1,a2,b1,b2;
    while(~scanf("%lf%lf%lf%lf%lf",&Rr,&a1,&b1,&a2,&b2))
    {
        double di=sqrt((a2-a1)*(a2-a1)+(b2-b1)*(b2-b1));
        if(di>=Rr)
          printf("%.9f %.9f %.9f" ,a1,b1,Rr);
        else
          if(di == 0)
            printf("%.9f %.9f %.9f",a1,b1-(Rr/2),(Rr/2));
        else
        {
            double r = (di + Rr)/2;
            double a = a2 + r*((a1-a2)/di);
            double b = b2 + r*((b1-b2)/di);
            printf("%.9f %.9f %.9f",a,b,r);
        }
    }
    return (0);
}
