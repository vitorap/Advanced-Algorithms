#include<cstdio>
#include<stack>
#include<queue>
using namespace std;
const int biggestN = 1000+100;
int id[biggestN],x[biggestN],n;

bool ehqueue(){
     queue<int >q;
      for(int i=0;i<n;i++){
        if(id[i]==1) q.push(x[i]);
        else{
            if(q.empty()) return false;
            int val=q.front();  q.pop();
            if(x[i]!=val) return false;
        }
    }
    return true;
}

bool ehstack(){
    stack<int> s;
    for(int i=0;i<n;i++){
        if(id[i]==1) s.push(x[i]);
        else{
            if(s.empty())  return false;
            int val=s.top();  s.pop();
            if(x[i]!=val) return false;
        }
    }
    return true;
}


bool ehPrioridade(){
    priority_queue<int > q;
      for(int i=0;i<n;i++){
        if(id[i]==1) q.push(x[i]);
        else{
             if(q.empty()) return false;
            int val=q.top();  q.pop();
            if(x[i]!=val) return false;
        }
    }
    return true;
}
int main(){
    while(scanf("%d",&n)!=EOF){
        bool st=false,qu=false,pr=false;
        for(int i=0;i<n;i++){
            scanf("%d %d",&id[i],&x[i]);
        }
        st=ehstack(); qu=ehqueue();  pr=ehPrioridade();
        if(!st&&!qu&&!pr)  puts("impossible");
        else if((!st&&qu&&pr)||(!qu&&st&&pr)||(!pr&&qu&&st)||(pr&&qu&&st)){
            puts("not sure");
        }
        else if(st) puts("stack");
        else if(qu) puts("queue");
        else if(pr) puts("priority queue");

    }
    return 0;
}
