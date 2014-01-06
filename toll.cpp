#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>

#define MAXN 260
#define A first
#define B second
#define LARGE 1e10


using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;

int pastures,paths,queries;

pii toll[MAXN];
ll adj[MAXN][MAXN];//dist then dest
ll ans[MAXN][MAXN];
ll curtoll[MAXN][MAXN];

int m[MAXN];//original index to new index

ll MAX(ll a,ll b){
    if(a<b) return b;
    else return a;
}

ll MAX(ll a,ll b,ll c){
    if(a>=b&&a>=c) return a;
    if(b>=a&&b>=c) return b;
    else return c; 

}
void init(){
    for(int y = 0;y<MAXN;y++){
        for(int x = 0;x<MAXN;x++){
            if(x==y){
                adj[x][x] = 0;
                ans[x][x] = toll[x].A;
            }
            else{
                adj[y][x] = LARGE;
                ans[y][x] = LARGE;
            }
        }
    }
}

int main(){
    freopen("toll.in","r",stdin);
    freopen("toll.out","w",stdout);
    scanf("%d%d%d",&pastures,&paths,&queries);
    for(int x = 0;x<pastures;x++){
        int a;
        scanf("%d",&a);
        toll[x] = pii(a,x);
        //x is original index
    }
    sort(toll,toll+pastures);
    for(int x = 0;x<pastures;x++){
        m[toll[x].B] = x;
    }
    init();

    for(int x = 0;x<paths;x++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        a--;
        b--;
        a = m[a];
        b = m[b];
        if(c<adj[a][b]){
            adj[a][b] = c;
            if(c+MAX(toll[a].A,toll[b].A)<ans[a][b]) ans[a][b] = c+MAX(toll[a].A,toll[b].A);
        }
        if(c<adj[b][a]){
            adj[b][a] = c;
            if(c+MAX(toll[a].A,toll[b].A)<ans[b][a]) ans[b][a] = c+MAX(toll[a].A,toll[b].A);
        }
    }
    for(int a = 0;a<pastures;a++){
        for(int x = 0;x<pastures;x++){
            for(int y = 0;y<pastures;y++){
                //ll cost = MAX(toll[x].A,toll[y].A,toll[a].A)+adj[x][a]-curtoll[x][a]+adj[a][y]-curtoll[a][y];
                if(adj[x][a]+adj[a][y]<adj[x][y]){
                    adj[x][y] = adj[x][a]+adj[a][y];
                    if(adj[x][y]+MAX(toll[x].A,toll[y].A,toll[a].A)<ans[x][y]) ans[x][y] =  adj[x][y]+MAX(toll[x].A,toll[y].A,toll[a].A);
                }
            }
        }
    }
    for(int x  = 0;x<queries;x++){
        int a,b;
        scanf("%d%d",&a,&b);
        a--;
        b--;

        printf("%lld\n",ans[m[a]][m[b]]);

    }




    
    return 0;

}
