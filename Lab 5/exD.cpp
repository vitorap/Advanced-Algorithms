#include<bits/stdc++.h>
using namespace std;
#define ll long long



char a[105][105];
int entrada[30];
int saida[30];
bool livro[30];
vector<int>v[35];
queue<int>q;


int main()
{
    int n;scanf("%d",&n);
    memset(livro,0,sizeof(livro));
    memset(entrada,0,sizeof(0));
    memset(saida,0,sizeof(0));
    while(!q.empty()) q.pop();
    for(int i=1;i<=n;i++)scanf("%s",&a[i]);
    for(int i=1;i<=n;i++)
    {

        for(int j=i+1;j<=n;j++)
        {
            int l=min(strlen(a[i]),strlen(a[j]));
            for(int k=0;k<l;k++)
            {
                if(a[i][k]!=a[j][k])
                {
                  //colocar um breaking point aqui
                    entrada[a[j][k]-'a'+1]++;
                    saida[a[i][k]-'a'+1]++;
                    v[a[i][k]-'a'+1].push_back(a[j][k]-'a'+1);
                    break;
                }
                if(k==l-1&&strlen(a[i])>strlen(a[j]))
                {
                    printf("Impossible");
                    return 0;
                }
            }
        }
    }

    int k=0;
    while(1)
    {
        int x=-1;
        for(int i=1;i<=26;i++)
        {
            if(entrada[i]==0&&!livro[i])
            {
                x=i;
                break;
            }
        }
        if(x==-1&&k<26)
        {
            // cout<<k<<endl;  --- teste
            cout<<"Impossible";
            break;
        }
        if(x==-1) break;
        k++;
        livro[x]=1;
        q.push(x);
        for(int i=0;i<v[x].size();i++)
        {
            entrada[v[x][i]]--;
        }
    }
    if(k==26)
    {
        while(!q.empty())
        {
            char t=q.front()+'a'-1;
            cout<<t;
            q.pop();
        }
    }
    return 0;
}
