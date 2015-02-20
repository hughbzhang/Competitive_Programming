#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#define A first
#define B second
#define MAXN 100100
#define LARGE 2000000001 

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

vector<pii> edge[MAXN];

priority_queue<pii,vector<pii>, greater<pii> > q;
bool vis[MAXN];
int dist[MAXN];
int N,M,a,b,c;
int dest = -1;
int one, two;
int S;

void clear(){
    for(int x = 0;x<MAXN;x++){
        dist[x] = LARGE;
        vis[x] = false;
    }
    while(!q.empty()) q.pop();
}

ll dijk(int s){
    clear();
    q.push(pii(0,s));
    dist[s] = 0;
    while(!q.empty()){
        pii cur = q.top();
        q.pop();

        if(vis[cur.B]) continue;
        vis[cur.B] = true;
//        cout<< cur.B << " " << cur.A << endl;
//        for(int x = 0;x<N;x++) cout << dist[x] << " ";
//        cout << endl;
        if(dest==-1){
            if(cur.B==one){
                S = one;
                dest = two;
                return dist[cur.B];
            }
            if(cur.B==two){
                S = two;
                dest = one;
                return dist[cur.B];
            }
        }
        else if(dest==cur.B)   return dist[dest];
        for(int x = 0;x<edge[cur.B].size();x++){
            if(edge[cur.B][x].A+dist[cur.B]<dist[edge[cur.B][x].B]){
                dist[edge[cur.B][x].B] = edge[cur.B][x].A+dist[cur.B];
                q.push(pii(dist[edge[cur.B][x].B],edge[cur.B][x].B));
            }
        }
    }
    return -1;
}

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> M >> N >> S >> one >> two;
    S--;
    one--;
    two--;
    for(int x  = 0;x<M;x++){
        cin >> a >> b >> c;
        a--;
        b--;
        edge[a].push_back(pii(c,b));
        edge[b].push_back(pii(c,a));
    }
    ll ans = dijk(S);
    ans += dijk(S);
    cout << ans << endl;
    return 0;

}
