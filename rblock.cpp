#include <cstdio>
#include <utility>
#include <vector>
#include <queue>
#define MAX 300
#define A first
#define B second
#define LARGE (1e15)

using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
typedef vector<pii>::iterator vi;

int num, M;
ll edge[MAX][MAX];
priority_queue<pii,vector<pii>,greater<pii> > q;
bool vis[MAX];
ll dist[MAX];
int pre[MAX];
ll ans = 0;


void init(){
    for(int x = 0;x<MAX;x++){
        for(int y = 0;y<MAX;y++){
            edge[y][x] = LARGE;
        }
        edge[x][x] = 0;
    }

}

void clear(){
    for(int x = 0;x<MAX;x++) vis[x] = false;
    for(int x = 0;x<MAX;x++) dist[x] = LARGE;
    while(!q.empty()) q.pop();
    dist[0] = 0;
}

ll search(bool flag){
    clear();
    q.push(pii(0,0));
    while(!q.empty()){
        pii NOW = q.top();
        q.pop();
        int cur = NOW.B;
        ll cost = NOW.A;
        if(vis[cur]) continue;
        vis[cur] = true;
        for(int a = 1;a<num;a++){
            if(cost+edge[cur][a]<dist[a]){
                dist[a] = cost+edge[cur][a];
                q.push(pii(dist[a],a));
                if(flag) pre[a] = cur;
            }
        }
    }
    return dist[num-1];
}

int main(){
    init();
    freopen("rblock.in","r",stdin);
    freopen("rblock.out","w",stdout);
    scanf("%d%d",&num,&M);
    for(int x = 0;x<M;x++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        a--;
        b--;
        edge[a][b] = c;
        edge[b][a] = c;
    }
    for(int x = 0;x<MAX;x++) pre[x] = -1;
    ll old = search(true);
    
    int first = pre[num-1];
    int sec = num-1;
    while(first!=-1){
        edge[first][sec]*=2;
        edge[sec][first]*=2;
        ll pos = search(false);
        if(pos>ans) ans = pos;
        edge[first][sec]/=2;
        edge[sec][first]/=2;
        first = pre[first];
        sec = pre[sec];
    }
    printf("%lld\n",ans-old); 


}
