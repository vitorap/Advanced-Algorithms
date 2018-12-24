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
#include <numeric>
#include <time.h>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)
#define E 2.71828182845904523536
#define long long LL
using namespace std;
map< pair<int,int>, vector<int> > CategorizationMemo;
string Qwerty = "  \n\n`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./";


int main()
{

    char Input;
    while(scanf("%c", &Input)==1) cout << Qwerty[Qwerty.find_last_of(Input) - 1];
    cout << endl;
    return 0;

}
