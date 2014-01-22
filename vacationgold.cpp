#include <cstdio>
#include <vector>
#include <queue>
#include <utility>

#define A first
#define B second
#define LARGE (1e8)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;//dist then dest
typedef vector<pii>::iterator vi;

int farms,flights,hubs,queries;
vector<pii> edge[20010][2];
int hub[201];
int price[201][20010][2];
//0 is in
//1 is out
bool vis[20010];
priority_queue<pii,vector<pii>, greater<pii> > q;
int cnt = 0;
ll ans = 0;

void init(){
    for(int y = 0;y<201;y++){
        for(int x = 0;x<20010;x++){
            price[y][x][0] = LARGE;
            price[y][x][1] = LARGE;
        }
    }
}
void clear(){
    for(int x = 0;x<20010;x++) vis[x] = false;
    while(!q.empty()) q.pop();
}

void search(int start, int flag){
    clear();
    price[start][hub[start]][flag] = 0;
    q.push(pii(0,hub[start]));
    while(!q.empty()){
        pii now = q.top();
        q.pop();
        ll dist = now.A;
        int cur = now.B;
        if(vis[cur]) continue;
        vis[cur] = true;
        for(vi it = edge[cur][flag].begin();it!=edge[cur][flag].end();++it){
            pii next = *it;
            ll cost = next.A;
            int dest = next.B;
            if(price[start][dest][flag]>cost+dist){
                price[start][dest][flag] = cost+dist;
                q.push(pii(cost+dist,dest));
            }
        } 
        
    }

}


int main(){
    init();
    freopen("vacationgold.in","r",stdin);
    freopen("vacationgold.out","w",stdout);
    scanf("%d%d%d%d",&farms,&flights,&hubs,&queries);
    int a,b,c;
    for(int x = 0;x<flights;x++){
        scanf("%d%d%d",&a,&b,&c);
        a--;
        b--;
        edge[a][1].push_back(pii(c,b));
        edge[b][0].push_back(pii(c,a));
    }
    for(int x = 0;x<hubs;x++){
        scanf("%d",hub+x);
        hub[x]--;
    }
    for(int x = 0;x<hubs;x++){
        search(x,0);
        search(x,1);
    }
    for(int x = 0;x<queries;x++){
        scanf("%d%d",&a,&b);
        a--;
        b--;
        ll pos = LARGE;
        for(int y = 0;y<hubs;y++){
            if(price[y][a][0]+price[y][b][1]<pos) pos = price[y][a][0]+price[y][b][1];
        }
        if(pos<LARGE){
            cnt++;
            ans+=pos;
        }

    }

    printf("%d\n%lld\n",cnt,ans);

    
    return 0;

}
