#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

#define A first
#define B second
#define MAX 200000
#define LARGE (1e15)

using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
typedef vector<pii>::iterator vi;

int vert,edges;
vector<pii> list[MAX];
bool vis[MAX];
int pre[MAX];
ll dist[MAX];
priority_queue<pii,vector<pii>, greater<pii> > q;
int ans[MAX];

void search(){
    for(int x = 0;x<MAX;x++) dist[x] = LARGE;
    dist[1] = 0;
    q.push(pii(0,1));
    while(!q.empty()){
        pii cur = q.top();
        q.pop();
        if(vis[cur.B]) continue;
        vis[cur.B] = true;
        for(vi it = list[cur.B].begin();it!=list[cur.B].end();++it){
            if(dist[it->B]>dist[cur.B]+it->A){
                pre[it->B] = cur.B;
                dist[it->B] = dist[cur.B]+it->A;
                q.push(pii(dist[it->B],it->B));
            }
        }
    }
}


int main(){
    freopen("dijkstra.in","r",stdin);
    freopen("dijkstra.out","w",stdout);
    cin >> vert >> edges;
    int a,b,c;
    for(int x = 0;x<edges;x++){
        cin >> a >> b >> c;
        list[a].push_back(pii(c,b));
        list[b].push_back(pii(c,a));
    }
    search();
    int cnt = 0;
    int now = vert;
//    for(int x = 0;x<=vert;x++) cout << dist[x] << endl;
 
    if(dist[vert]==LARGE) cout << -1 << endl;

    else{
       while(now!=0){
            ans[cnt] = now;
            cnt++;
            now = pre[now];
        }
    }
    for(int x = cnt-1;x>=0;x--) cout << ans[x] << " ";
    return 0;
}
