#include <cstdio>
#include <vector>

using namespace std;

const int maior_valor = 7490;
int coins[] = {1, 5, 10, 25, 50};

int main()
{
    vector<long long> caminho(maior_valor, 0);
    caminho[0] = 1;

    for (int coin = 0; coin < 5; ++coin)
        for (int from = 0, i = coins[coin]; i < maior_valor; ++from, ++i)
            caminho[i] += caminho[from];

    int quero;
    while (scanf("%d", &quero) == 1)
    {
        printf("%d\n", int(caminho[quero]));
    }
}
