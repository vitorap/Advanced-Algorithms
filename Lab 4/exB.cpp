#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ll ax,ay,bx,by,cx,cy;
    cin>>ax>>ay>>bx>>by>>cx>>cy;
    if(ax==bx&&bx==cx)
      cout<<"No\n";
    else
      if((cy-by)*(bx-ax)==(cx-bx)*(by-ay))
        cout<<"No\n";
      else
        if((by-ay)*(by-ay)+(bx-ax)*(bx-ax)==(cy-by)*(cy-by)+(cx-bx)*(cx-bx))
          cout<<"Yes\n";
        else
          cout<<"No\n";
    return (0);
}
