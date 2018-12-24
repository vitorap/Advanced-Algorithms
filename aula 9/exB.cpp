#include<iostream>
#include<cstdio>
using namespace std;
#define inf 2000000000000
long long int dinheiro;
int b = 0,s = 0,c = 0;
int nb,ns,nc;
int pb,ps,pc;
int jud(long long int mid,long long int &m){
  long long int bb = (mid*b) - nb;
  long long int ss = (mid*s) - ns;
  long long int cc = (mid*c) - nc;
  if(bb < 0) bb = 0;
  if(ss < 0) ss = 0;
  if(cc < 0) cc = 0;
  m = (bb)*pb + (ss)*ps + (cc)*pc;
  if(m > dinheiro)
    return 1;
  else
    return 0;
}
int main()
{
  char x;
  while(scanf("%c",&x) && x != '\n'){
    switch(x){
      case 'B': b++;break;
      case 'S': s++;break;
      case 'C': c++;break;
    }
  }
  cin >> nb >> ns >> nc;
  cin >> pb >> ps >> pc;
  cin >> dinheiro;
  long long int l = 1,r = inf,cnt = -1;
  while(l <= inf && l < r){
    long long int mid = (l + r)/2,m;
    int juiz = jud(mid,m);
    if(juiz == 0){
      cnt = cnt > m?cnt : m;
      l = mid + 1;
    }else{
      r = mid;
    }
  }
  cout << l - 1 << endl;
  return 0;
}
