#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#define MAXM 50500
#define MAXN 10010
#define MAXK 25
#define A first
#define B second
#define LARGE 1000000000000;

using namespace std;
typedef pair<int,int> pii;//distance then destination
typedef pair<int, pii> piii;//revamps first
typedef priority_queue<piii,vector<piii>,greater<piii> > HEAP;
typedef long long ll;

HEAP heap;
int pastures,trails,revamps;
vector<pii> adj[MAXN];
ll dist[MAXN][MAXK];//k is revamps used N is pasture #
bool vis[MAXN][MAXK];

void init(){
    for(int x = 0;x<=pastures;x++){
        for(int y = 0;y<=revamps;y++){
            dist[x][y] = LARGE;
        }
    }
}

ll search(){
    dist[1][0] = 0;
    heap.push(piii(0,pii(0,1)));
    while(!heap.empty()){
        piii top = heap.top();
        int vamps = top.A;//how many we used
        int old = top.B.A;//how far we are
        int cur = top.B.B;//where we are
        heap.pop();
        if(vis[cur][vamps]) continue;
        vis[cur][vamps] = true;
        if(cur==pastures&&vamps==revamps) return old;
        vector<pii>::iterator it = adj[cur].begin();
        vector<pii>::iterator end = adj[cur].end();
        while(it!=end){
            pii pos = *it;
            int length = pos.A;
            int dest = pos.B;
            if(length+old<dist[dest][vamps]){
                dist[dest][vamps] = length + old;
                heap.push(piii(vamps,pii(dist[dest][vamps],dest)));
            }
            if(vamps<revamps){
                if(old<dist[dest][vamps+1]){
                    dist[dest][vamps+1] = old;
                    heap.push(piii(vamps+1,pii(dist[dest][vamps+1],dest)));
                }
            }
            ++it;
        }
        

    }
    return dist[pastures][revamps];

}
void print(){
    for(int y = 0;y<=revamps;y++){
        for(int x = 0;x<=pastures;x++){
            printf("%lld ",dist[x][y]);
        }
        printf("\n");
    }
}


int main(){
    freopen("revamp.in","r",stdin);
    freopen("revamp.out","w",stdout);
    scanf("%d%d%d",&pastures,&trails,&revamps);
    int a,b,c;
    for(int x = 0;x<trails;x++){
        scanf("%d%d%d",&a,&b,&c);
        adj[a].push_back(pii(c,b));
        adj[b].push_back(pii(c,a));
    }
    /*for(int x = 0;x<pastures;x++){
        int size = adj[x].size();
        printf("%d %d\n",x,size);
    }*/
    init();
    ll answer = search();
    printf("%lld\n",answer);
    //print();
    return 0;
}
