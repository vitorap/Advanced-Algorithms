#include <cstdio>
#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int aux, N, freshSum, freshSI, freshEI, MS, maxSI, maxEI, tem;
    tem = 1;
    int A[20005];
    scanf("%d", &aux);
    while(aux--){
        scanf("%d", &N);
        N--;
        for(int i = 1; i <= N; i++)
            scanf("%d", &A[i]);

        freshSum = 0;
        freshSI = 1;
        MS = INT_MIN;
        for(freshEI = 1; freshEI <= N; freshEI++){
            freshSum += A[freshEI];
            if(freshSum < 0){
                freshSI = freshEI + 1;
                freshSum = 0;
            }
            if(freshSum > MS || (freshSum == MS && (maxEI-maxSI < freshEI- freshSI))){
                MS = freshSum;
                maxSI = freshSI;
                maxEI = freshEI;
            }
        }
        if(MS > 0)printf("The nicest part of route %d is between stops %d and %d\n", tem++, maxSI, maxEI+1);
        else printf("Route %d has no nice parts\n", tem++);
    }
    return 0;
}
