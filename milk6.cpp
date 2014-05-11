/*
ID: bigfish2
LANG: C++
TASK: milk6
*/
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

#define A first
#define B second

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<ll,piii> piiii;

bool use[1001];
ll adj[40][40];
ll change[40][40];
int cnt[40][40];
vector<int> list[40][40];
vector<int> done;
vector<piiii> edge;
vector<int> ans;
const ll LARGE = 10000000000;

int N,M;

bool vis[40];
ll best[40];
int par[40];
void clear(){
    for(int x = 0;x<40;x++){
        vis[x] = 0;
        best[x] = 0;
        par[x] = -1;
    }
    
}
void copy(){
    for(int y = 0;y<40;y++){
        for(int x = 0;x<40;x++){
            change[y][x] = adj[y][x];
        }
    }
}

ll dijk(){
    clear();
    int cur = 0;
    best[0] = LARGE;
    while(cur!=-1){
        vis[cur] = true;
        for(int x = 0;x<N;x++){
            ll next = min(change[cur][x],best[cur]);    
            if(next>best[x]){
                best[x] = next;
                par[x] = cur;
            }
        }
        int lol = 0;
        cur = -1;
        for(int x = 0;x<N;x++){
            if(!vis[x]&&best[x]>lol){
                cur = x;
                lol = best[x];
            }
        }
    }
    cur = N-1;
    int past = par[cur];
    while(par[cur]!=-1){
        change[past][cur]-=best[N-1];
        change[cur][past]+=best[N-1];
        cur = par[cur];
        past = par[past];
    }
//    for(int x = 0;x<N;x++) printf("%lld\n",best[x]);
    return best[N-1];
}
ll flow(){
    copy();
    ll all = 0;
    ll next = dijk();
    while(next){
        all+=next;
        next = dijk();
    }
    return all;
}

int main(){
    freopen("milk6.in","r",stdin);
    freopen("milk6.out","w",stdout);
    scanf("%d%d",&N,&M);
    int a,b;
    ll c;

   for(int x = 0;x<M;x++){
        scanf("%d%d%lld",&a,&b,&c);
        a--;
        b--;
        adj[a][b] += c; 
        cnt[a][b]++;
        list[a][b].push_back(x+1);
    }
    for(int y = 0;y<N;y++){
        for(int x = 0;x<N;x++){
            adj[y][x]*=1001;
            adj[y][x]+=cnt[y][x];
            if(adj[y][x]) edge.push_back(piiii(adj[y][x],piii(list[y][x][0],pii(y,x))));
        }
    }
    sort(edge.begin(),edge.end());
    ll cap = flow();
    ll cut = cap;
    while(cap>0){
        for(int x = 0;x<edge.size();x++){
            if(use[x]) continue;
            piiii now = edge[x];
            adj[now.B.B.A][now.B.B.B] = 0;
            ll next = flow();
            if(cap-next==now.A){
                //printf("REM %lld\n",now.A);
                use[x] = true;
                ans.push_back(x);
                break;
            }
            adj[now.B.B.A][now.B.B.B] = now.A;
        }
        cap = flow();
        //printf("CAP %lld\n",cap);
    }
    
    for(int x = 0;x<ans.size();x++){
        int start = edge[ans[x]].B.B.A;
        int end = edge[ans[x]].B.B.B;
        for(int x = 0;x<list[start][end].size();x++) done.push_back(list[start][end][x]);
    }
    sort(done.begin(),done.end());
    int number = done.size();
    cut-=number;
    cut/=1001;
    printf("%lld %d\n",cut,number);
    for(int x = 0;x<done.size();x++){
        printf("%d\n",done[x]);
    }
    

    return 0;
}
