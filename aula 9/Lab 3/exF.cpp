#include <math.h>
#include <stdio.h>
#define max(n,m) ((n)>(m)?(n):(m))

int aux[1000001],cont[1000001];


int main()
{
	int n,i,j,x,ans=0;
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		scanf("%d",&x);
		cont[x]++;
	}
	for (i=1;i<=1000000;i++)
		if (cont[i])		{
			aux[i]=max(aux[i],1);
			for (j=i+i;j<=1000000;j+=i)
				if (cont[j])
					aux[j]=max(aux[j],aux[i]+1);
		}
	for (i=1;i<=1000000;i++)
		ans=max(ans,aux[i]);
	printf("%d",ans);
	return 0;
}
