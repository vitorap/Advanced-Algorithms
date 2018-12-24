#include <stdio.h>
#include<vector>

using namespace std;


int main(){
    int x[300],i=0,k=1,j=0,tam=0;
    while(scanf("%d",&x[tam])!=EOF){
        tam++;
    }

    while (k==1){
        k=0;
        for (i=1;i<tam;i++) {
            if (x[i]>x[i-1]){
                j=x[i];
                x[i]=x[i-1];
                x[i-1]=j;
                k=1;
            }
        }
    }


    for (j=tam-1;j>=0;j--){
        printf("%d\n", x[j]);
    }
    printf("\n");
    for (j=0;j<i;j++){
        printf("%d\n", x[j]);
    }
}
