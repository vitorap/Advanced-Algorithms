#include <stdio.h>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;

#define integer unsigned long long

int main() {
	bool ehprimo[65536];
	memset(ehprimo, true, sizeof(ehprimo));
	vector<integer> primo;
	for (integer a = 2; a < 65536; a++)
		if (ehprimo[a]) {
			primo.push_back(a);
			for (integer b = a * a; b < 65536; b += a)
				ehprimo[b] = false;
		}
	integer n, mm;
	while (cin >> n >> mm) {
		vector<integer> factor, exp;
		integer m = mm;
		for (int a = 0; a < (int)primo.size() && m > 1; a++) {
			if (m % primo[a] == 0) {
				factor.push_back(primo[a]);
				exp.push_back(0);
				while (m % primo[a] == 0) {
					exp[exp.size() - 1]++;
					m /= primo[a];
				}
			}
		}
		if (m > 1) {
			factor.push_back(m);
			exp.push_back(1);
		}
		bool divisivel = (mm != 0);
		for (int a = 0; a < (int)factor.size(); a++) {
			integer b = n;
			int contador = 0;
			while (b >= factor[a]) {
				b /= factor[a];
				contador += b;
			}
			if ((int)contador < (int)exp[a]) {
				divisivel = false;
				break;
			}
		}
		if (divisivel)
			printf("%llu divides %llu!\n", mm, n);
		else
			printf("%llu does not divide %llu!\n", mm, n);
	}
	return 0;
}
