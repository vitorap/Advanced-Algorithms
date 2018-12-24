#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll x;
    cin>>x;
    if(x>-1)
    {cout<<x<<endl; return 0;}
    else
    {
        if((x-(x%10))/10 > ((x%10)+(x-(x%100))/10))
            cout<<(x-(x%10))/10<<endl;
        else
            cout<<((x-(x%100))/10)+(x%10)<<endl;
    }


    return 0;
}
