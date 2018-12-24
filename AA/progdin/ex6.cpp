#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define mS 1<<12
#define mN 12
//==============================================

int DP[mS][mN], mat[20][20];

//==============================================

int TSP(int stt, int ultimo, int n) {
	if(stt == 0 && ultimo != 0)	return 0xfffff;
	if(DP[stt][ultimo] != -1)	return DP[stt][ultimo];
	int i, min = 0xfffff, tmp;
	for(i = 0; i <= n; i++) {
		if((stt&(1<<i)) != 0) {
			tmp = TSP(stt-(1<<i), i, n);
			tmp += mat[i][ultimo];
			if(min > tmp)	min = tmp;
		}
	}
	DP[stt][ultimo] = min;
	return DP[stt][ultimo];
}



//==============================================
int main() {
	int T, x[20], y[20];
	int tamx, tamy, n, i, j;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &tamx, &tamy);
		scanf("%d %d", &x[0], &y[0]);
		scanf("%d", &n);
		for(i = 1; i <= n; i++)
			scanf("%d %d", &x[i], &y[i]);
		for(i = 0; i <= n; i++)
			for(j = 0; j <= n; j++)
				mat[i][j] = abs(x[i]-x[j])+abs(y[i]-y[j]);
		memset(DP, -1, sizeof(DP));
		DP[0][0] = 0;
		printf("The shortest path has length %d\n", TSP((1<<(n+1))-1, 0, n));
	}
    return (0);
}
