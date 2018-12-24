#include <cstring.h>
#include <queue.h>
#include <cstdio.h>
#include <algorithm.h>

using namespace std;
typedef long long LL;
typedef pair <LL,int> pii;
const int maxn = 100010;
const int maxm = 200010;
int v[maxm],next[maxm],w[maxm];
int first[maxn],pre[maxn],res[maxn],e;
LL d[maxn];

void init(){
    e = 0;
    memset(first,-1,sizeof(first));
}

void adc_canto(int x,int y,int z){
    v[e] = y;next[e] = first[x];w[e] = z;first[x] = e++;
}

void dijkstra(int src){
    priority_queue <pii,vector<pii>,greater<pii> > q;
    memset(d,-1,sizeof(d));
    d[src] = 0;
    q.push(make_pair(0,src));
    while(!q.empty()){
        while(!q.empty() && q.top().first > d[q.top().second])  q.pop();
        if(q.empty())   break;
        int u = q.top().second;
        q.pop();
        for(int i = first[u];i != -1;i = next[i]){
            if(d[v[i]] > d[u]+w[i] || d[v[i]] == -1){
                d[v[i]] = d[u]+w[i];
                q.push(make_pair(d[v[i]],v[i]));
                pre[v[i]] = u;
            }
        }
    }
}

int main(){
    init();
    int n,m,x,y,z;
    scanf("%d%d",&n,&m);
    for(int i = 0;i < m;i++){
        scanf("%d%d%d",&x,&y,&z);
        adc_canto(x,y,z);
        adc_canto(y,x,z);
    }
    dijkstra(1);
    int agr = n,count = 0;
    if(d[n] == -1){
        printf("-1");
        return 0;
    }
    while(agr != 1){
        res[count++] = agr;
        agr = pre[agr];
    }
    res[count++] = 1;
    for(int i = count-1;i >= 0;i--)  printf("%d ",res[i]);
    return 0;
}
