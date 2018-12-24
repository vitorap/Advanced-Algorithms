int main()
{
    int n_lojas;
    scanf("%d", &n_lojas);

    vector <int> preco_loja(n_lojas);
    for(int i = 0; i < n_lojas; i++)
        scanf("%d", &preco_loja[i]);

    sort(all(preco_loja));

    int n_dias, orcamento_dia;
    scanf("%d", &n_dias);

    for(int i = 1; i <= n_dias; i++)
    {
        scanf("%d", &orcamento_dia);
        int n_lojas_eligiveis = upper_bound(all(preco_loja), orcamento_dia) - preco_loja.begin();

        printf("%d\n",n_lojas_eligiveis);
    }
    return 0;
}
