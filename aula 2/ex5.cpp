#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>

using namespace std;

struct Selecao{
    int numJogos, numVit, numEmp, numDer,
        numGols, numGolsContra, numPontos;
    char* name;
    Selecao(char* TN) {
        name = TN;
        numJogos = 0, numVit = 0, numEmp = 0, numDer = 0,
            numGols = 0, numGolsContra = 0, numPontos = 0;
    }
    Selecao(){
        numJogos = 0, numVit = 0, numEmp = 0, numDer = 0,
            numGols = 0, numGolsContra = 0, numPontos = 0;
    }
};

bool comparadorSelecao(pair<string,Selecao> e1, pair<string,Selecao> e2){
    Selecao t1 = e1.second, t2 = e2.second;
    int p_a = t1.numVit*3 + t1.numEmp, p_b = t2.numVit*3 + t2.numEmp;
    int gd_a = t1.numGols - t1.numGolsContra;
    int gd_b = t2.numGols - t2.numGolsContra;

    if (p_a != p_b) return p_a > p_b;
    if (t1.numVit != t2.numVit) return t1.numVit > t2.numVit;
    if (gd_a != gd_b) return gd_a > gd_b;
    if (t1.numGols != t2.numGols) return t1.numGols > t2.numGols;
    if (t1.numJogos != t2.numJogos) return t1.numJogos < t2.numJogos;

    for(int x=0; x < int(strlen(t1.name)); x++)
        t1.name[x] = tolower(t1.name[x]);
    for(int x=0; x < int(strlen(t2.name)); x++)
        t2.name[x] = tolower(t2.name[x]);

    return strcmp( t1.name, t2.name) < 0;

}

int main(){
    int N; scanf("%d\n", &N);
    for(int n = 0; n<N; n++){
        char nomeCampeonato[101]; fgets(nomeCampeonato,101,stdin);
        nomeCampeonato[strlen(nomeCampeonato)-1]='\0';
        int numSelecoes; scanf("%d\n", &numSelecoes);
        map<string, Selecao> selecoes;
        for(int nt = 0; nt<numSelecoes; nt++){
            char nomeSelec[31];
            fgets(nomeSelec,30,stdin);
            nomeSelec[strlen(nomeSelec)-1]='\0';
            Selecao t = Selecao(nomeSelec);
            selecoes.insert(make_pair(nomeSelec, t));
        }

        int numJogos; scanf("%d\n", &numJogos);
        char jogo[1001];

        for(int ng = 0; ng<numJogos; ng++){
           fgets(jogo,1001,stdin);
            jogo[strlen(jogo)-1]='\0';
            int x = 0, y = 0;
            char nomeSelA[31], nomeSelB[31];
            while(jogo[x]!='#'){nomeSelA[y++] = jogo[x++];}
            nomeSelA[y] = '\0'; y = 0; x++;
            char numArtilheirosA[16], numArtilheirosB[16];
            int numGolsA, numGolsB;
            while(jogo[x]!='@'){numArtilheirosA[y++] = jogo[x++];}
            numArtilheirosA[y] = '\0'; numGolsA = atoi(numArtilheirosA); y = 0; x++;
            while(jogo[x]!='#'){numArtilheirosB[y++] = jogo[x++];}
            numArtilheirosB[y] = '\0'; numGolsB = atoi(numArtilheirosB); y = 0; x++;
            while(jogo[x]!='\0'){nomeSelB[y++] = jogo[x++];}
            nomeSelB[y] = '\0'; y = 0; x++;

            Selecao *ta = & selecoes[nomeSelA]; Selecao *tb = & selecoes[nomeSelB];

            (ta->numJogos)++; (tb->numJogos)++;
            ta->numGols += numGolsA; tb->numGols += numGolsB;
            ta->numGolsContra += numGolsB; tb->numGolsContra += numGolsA;

            if(numGolsA == numGolsB) (ta->numEmp)++, (tb->numEmp)++;
            else if(numGolsA > numGolsB) (ta->numVit)++, (tb->numDer)++;
            else (ta->numDer)++, (tb->numVit)++;
        }


        vector< pair<string, Selecao> > sortSelec;

        copy(selecoes.begin(), selecoes.end(), back_inserter(sortSelec));

        sort(sortSelec.begin(), sortSelec.end(), comparadorSelecao);

        puts(nomeCampeonato);
        for (int y = 0; y<int(sortSelec.size()); y++){
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
                y+1, sortSelec[y].first.c_str(),
                sortSelec[y].second.numVit*3 + sortSelec[y].second.numEmp,
                sortSelec[y].second.numJogos, sortSelec[y].second.numVit,
                sortSelec[y].second.numEmp, sortSelec[y].second.numDer,
                sortSelec[y].second.numGols - sortSelec[y].second.numGolsContra,
                sortSelec[y].second.numGols, sortSelec[y].second.numGolsContra);
        }
        if (n != N-1) printf("\n");
    }
    return 0;
}
