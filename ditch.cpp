/*
ID: bigfish2
LANG: C++
TASK: ditch
*/

#include <cstdio>
#include <cmath>
#include <utility>
#include <queue>
#define MAXN 220
#define LARGE 1000000000
#define A first
#define B second

using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;//first the cost, then the end


ll adj[MAXN][MAXN];//adj matrix when looking up makes sure that the first one is the start since it is a directed graph
int ditches,sink;
priority_queue<pii> heap;


int pre[MAXN];//preceder in the sequence
bool vis[MAXN];
ll flow[MAXN];
ll totalflow = 0;

void clear(){
    heap = priority_queue<pii>();
    for(int x = 0;x<=sink;x++){
        flow[x] = 0;
        vis[x] = false;
        pre[x] = 0;
    }
    flow[1] = LARGE;
}

bool path(){//finds the maximum flow path. If no path flow[sink] will be 0
    while(true){    
        clear();
        heap.push(pii(LARGE,1));
        while(true){
            while(!heap.empty()&&vis[heap.top().B]) heap.pop();
            if(heap.empty()) break;
            ll dist = heap.top().A;
            int cur = heap.top().B;
            vis[cur] = true;
            if(cur==sink) break;
            heap.pop();
            for(int x = 2;x<=sink;x++){
                ll next = min(adj[cur][x],dist);
                if(next>flow[x]){
                    flow[x] = next;
                    pre[x] = cur;
                    heap.push(pii(next,x));
                }
            }
        }
        if(!flow[sink]) break;
        int cur = sink;
        while(cur!=1){
            adj[pre[cur]][cur]-=flow[sink];
            adj[cur][pre[cur]]+=flow[sink];
            cur = pre[cur];
        }
        totalflow += flow[sink];
    }
}


int main(){
    freopen("ditch.in","r",stdin);
    freopen("ditch.out","w",stdout);
    scanf("%d%d",&ditches,&sink);
    int a,b;
    ll c;
    for(int x = 0;x<ditches;x++){
        scanf("%d%d%lld",&a,&b,&c);
        adj[a][b] += c;
    }
    path();
    printf("%lld\n",totalflow);
    return 0;
}
