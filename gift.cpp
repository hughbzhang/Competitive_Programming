#include <cstdio>
#include <cmath>
#include <queue>

using namespace std;

queue <int> q;
int par[200200];
int child[200200];
long long z[200200];
long long w[200200];
bool vis[200200];
int T,N;

int main(){
    freopen("in.txt","r",stdin);
    scanf("%d",&T);
    for(int x = 0;x<T;x++){
        scanf("%d",&N);
        vis[0] = false;
        for(int b = 1;b<=N;b++){
            scanf("%d",&par[b]);
            child[par[b]]++;
            vis[b]= false;
        }
        for(int b = 1;b<=N;b++){
            if(child[b]==0) q.push(b);
            printf("%d\n",par[b]);
        }
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            if(cur==0) break;
            if(vis[cur]) continue;
            w[cur]++;
            z[par[cur]]+=w[cur];
            w[par[cur]]+=z[cur];
            child[par[cur]]--;
            vis[cur] = true;
            if(!vis[par[cur]]&&child[par[cur]]==0) q.push(par[cur]);
            printf("%d %lld %lld\n",cur,w[cur],z[cur]);
        }
        printf("Case #%d: %lld\n",x,N+min(w[0],z[0]));
    }
}

   
