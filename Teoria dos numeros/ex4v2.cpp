#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int mdc(int x, int y) {
	if (x == 0)
		return y;
	else
		return mdc(y % x, x);
}

int main() {
	int x;
	cin >> x;
	while (x) {
		vector<int> v;
		do {
			v.push_back(x);
			cin >> x;
		} while (x);
		unique(v.begin(), v.end());
		vector<int> z;
		for (int i = 1; i <(int) v.size(); i++)
			z.push_back(v[i] - v[i - 1]);
		int g = abs(z[0]);
		for (int i = 1; i <(int) z.size(); i++)
			g = mdc(g, abs(z[i]));
		cout << g << endl;
		cin >> x;
	}
	return 0;
}
