#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <vector>

using namespace std;
map< pair<int,int>, vector<int> > CategorizationMemo;
string Teclado = "  \n\n`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";


int main()
{

    char Digita;
    while(scanf("%c", &Digita)==1) cout << Teclado[Teclado.find_last_of(Digita) - 1];
    return 0;

}
