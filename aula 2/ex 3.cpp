#include <stdio.h>
int main(void)
{
    int a[30000],pilha[1000];
    int x,tam,y;
    while(scanf("%d",&a[0])!=EOF)  {
     x=1;
     while(getchar()!='\n')
      scanf("%d",&a[x++]);
     tam=x;
     if(x%2) {
      printf(":-( Try again.\n");
      continue;
     }
     int contador[1000]={0};

     //Como determinar se cada número ta fora de alcance?

     pilha[0]=a[0];
     for(x=1,y=0;x<tam&&y>=0;x++)
     {
      if(a[x]<0)
       pilha[++y]=a[x];
      else
      {
       if(!(pilha[y]+a[x])&&pilha[y]+contador[y]<0)  {
           contador[y]=0;  y--; contador[y]+=a[x];
       }
       else
       {
        printf(":-( Try again.\n");
        break;
       }
      }
     }
     if(y==-1)
      printf(":-) Matrioshka!\n");
    }
    return 0;
}

