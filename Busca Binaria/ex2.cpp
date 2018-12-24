#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
  double distplitro = 100.0;
  while (true) {
    int p, n;
    const int ncharmaximo = 15;
    char s[ncharmaximo + 1];
    scanf("%d %s %*s %d", &p, s, &n);
    if (!n)
      break;
    int pp = p, l = 0;
    double tanque = 0.0, tanque_max = 0.0;
    bool objt = false;
    do {
      scanf("%d %s", &p, s);
      int d = p - pp;
      pp = p;
      tanque += d / distplitro * n + d * l;
      tanque_max = max(tanque_max, tanque);
      switch (s[0]) {
      case 'F': // F de Fuel - Combustivel
        scanf("%*s %d", &n);
        break;
      case 'L':
        l++;
        break;
      case 'G': //  mesma coisa
        if (s[1] == 'a') {
          scanf("%*s");
          tanque = 0.0;
        }
        else
          objt = true;
        break;
      case 'M':
        l = 0;
        break;
      }
    } while (!objt);
    printf("%.3lf\n", tanque_max);
  }
  return 0;
}
