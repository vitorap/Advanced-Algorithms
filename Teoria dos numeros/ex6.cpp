#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;
const int N = 1005;
typedef long long vlong;

int m;
vlong c[N];

void start (vlong z) {
	m = 0;

	vlong t = sqrt(z);
	for (vlong i = 1; i <= t; i++) {
		if (z % i == 0) {
			c[m++] = i;
			if (z / i != i)
				c[m++] = z / i;
		}
	}
	sort (c, c + m);
}

vlong mdc (vlong x, vlong y) {
	return y == 0 ? x : mdc(y, x%y);
}

int solution (vlong n) {
	int resp = 0;
	for (int i = 0; i <m; i++) {
		for (int j = i; j <m; j++) {
			if (c[i] * c[j] / mdc(c[i], c[j]) == n)
				resp++;
		}
	}
	return resp;
}

int main () {
	vlong n;
	while (scanf("%lld", &n), n) {
		start (n);
		printf("%lld %d\n", n, solution(n));
	}
	return 0;
}
