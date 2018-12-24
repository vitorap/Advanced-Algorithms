#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct no
{
    int pos,h;
}vetA[100050];
int pdd[100050][2];
int pmc(no vetA,no vetB)
{
    return vetA.pos<vetB.pos;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&vetA[i].pos,&vetA[i].h);
        }
        vetA[n].pos=2000000600;
        sort(vetA,vetA+n,pmc);
        memset(pdd,0,sizeof(pdd));
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                pdd[i][0]=1;
                if(vetA[i].pos+vetA[i].h<vetA[i+1].pos)
                pdd[i][1]=1;
            }
            else
            {
                pdd[i][1]=max(pdd[i-1][1],pdd[i-1][0]);
                pdd[i][0]=max(pdd[i-1][1],pdd[i-1][0]);
                if(vetA[i].pos+vetA[i].h<vetA[i+1].pos)
                pdd[i][1]=max(pdd[i][1],pdd[i-1][0]+1);
                if(vetA[i].pos+vetA[i].h<vetA[i+1].pos)
                pdd[i][1]=max(pdd[i][1],pdd[i-1][1]+1);
                if(vetA[i].pos-vetA[i].h>vetA[i-1].pos)
                pdd[i][0]=max(pdd[i][0],pdd[i-1][0]+1);
                if(vetA[i].pos-vetA[i].h>vetA[i-1].pos+vetA[i-1].h)
                pdd[i][0]=max(pdd[i][0],pdd[i-1][1]+1);
            }
        }
        printf("%d\n",max(pdd[n-1][1],pdd[n-1][0]));
    }
}
