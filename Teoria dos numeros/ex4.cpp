#include <bits/stdc++.h>
using namespace std;

typedef long vlong; //vlong = long long mas nao tava tendo espaco suficiente em memoria no runcondes

vlong mdc ( vlong x, vlong y ) {
    while ( y ) {
        x = x % y;
        swap ( x, y );
    }
    return x;
}

vlong vet[1010];

int main () {

    while ( scanf ( "%ld", &vet[0] ) != EOF ) {
        if ( vet[0] == 0 ) break; //fim do teste
        //x novo teste
        int aux = 1;

        //entrada
        while ( 1 ) {
            scanf ( "%ld", &vet[aux] );
            if ( vet[aux] == 0 ) break;
            else aux++;
        }

        vlong g = 0;
        for ( int i = 1; i < aux; i++ ) {
            int dif = vet[i] - vet[i-1];
            g = mdc ( g, dif ); //Encontra mdc das diferencas
        }

        if ( g < 0 ) g *= -1; //Caso encontre mdc negativo
        printf ( "%ld\n", g );
    }

    return 0;
}
