#include<bitset>
#include<cstdio>
#include<vector>

using namespace std;

int i, l, h;
bitset<10000010> bs;
vector<int> primos;

void filtro(long long limsup) {
    bs.set();
    bs[0] = bs[1] = 0;
    for(long long a = 2; a <= limsup + 1; a++) {
        if(bs[a]) {
            for(long long b = a * a; b <= limsup + 1; b += a)
                bs[b] = 0;
            primos.push_back((int) a);
        }
    }
}

int nfat(int i) {
    int fp = 0;
    int pf = primos[fp];
    int result = 1;

    while(pf * pf <= i) {
        int j = 0;
        while(i % pf == 0) {
            j++;
            i /= pf;
        }
        pf = primos[++fp];
        result *= (j + 1);
    }
    if(i != 1) result *= 2;

    return result;
}

int main() {
    filtro(35000);
    scanf("%d", &i);
    while(i--) {
        scanf("%d %d", &l, &h);
        int melhor = 0, melhorInd = 0;
        for(int a = l; a <= h; a++) {
            int b = nfat(a);
            if(b > melhor) {
                melhor = b;
                melhorInd = a;
            }
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n", l, h, melhorInd, melhor);
    }
}
