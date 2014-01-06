#include <cstdio>
#include <utility>
#include <vector>
#include <queue>
#include <set>

#define A first
#define B second
#define LARGE 10000000

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;//dist,dest
typedef pair<pii,int> piii;//cur tax
typedef pair<ll,int> lll;
typedef vector<pii>::iterator it;
int pastures,paths,queries;
vector<pii> adj[250];
int tax[300];
ll dist[250][250];
int curtax[250][250];
bool vis[250];
set<int> list;
int test[250];
int diff = 0;

priority_queue<pii,vector<pii>,greater<pii> > q;
priority_queue<piii,vector<piii>,greater<piii> > TODO;

void reset(){
    for(int x = 0;x<250;x++) vis[x] = false;
    while(!q.empty()) q.pop();
    while(!TODO.empty()) TODO.pop();
}

void search(int start,int limit){

    if(tax[start]>limit) return;

    while(!q.empty()) q.pop();
    if(vis[start]==false) TODO.push(piii(pii(tax[start],start),0));
    if(TODO.top().A.A>limit) return;
    while(!TODO.empty()&&TODO.top().A.A<=limit){
        q.push(pii(TODO.top().B,TODO.top().A.B));
        TODO.pop();
    } 


    while(!q.empty()){
        pii now = q.top();
        q.pop();
        int cost = now.A;
        int cur = now.B;
        if(vis[cur]) continue;
        vis[cur] = true;
        dist[start][cur] = cost;
        curtax[start][cur] = limit;
        for(it i = adj[cur].begin();i!=adj[cur].end();++i){
            int price = (*i).A;
            int dest = (*i).B;
            if(tax[dest]>limit){
                TODO.push(piii(pii(tax[dest],dest),cost+price));
                continue;
            }
            if(price+cost+limit<dist[start][dest]+curtax[start][dest]){
                dist[start][dest] = price+cost;
                curtax[start][dest] = limit;
            }
            q.push(pii(price+cost,dest));
        }
    }
}
int max(int a,int b){
    if(a<b) return b;
    else return a;
}
int print(int a,int b){return adj[a][b].A+adj[a][b].B;}

int main(){
    freopen("toll.in","r",stdin);
    freopen("toll.out","w",stdout);
    scanf("%d%d%d",&pastures,&paths,&queries);
    for(int x = 0;x<pastures;x++){
        scanf("%d",tax+x);
        list.insert(tax[x]);
    }
    for(set<int>::iterator i = list.begin();i!=list.end();++i){
        test[diff] = *i;        
        diff++;
    }
    for(int x = 0;x<250;x++){
        for(int y = 0;y<250;y++){
            
            dist[y][x] = LARGE;
            if(x==y) dist[y][x] = 0;
        }
    }
    int a,b,c;
    for(int x = 0;x<paths;x++){
        scanf("%d%d%d",&a,&b,&c);
        a--;
        b--;
        adj[b].push_back(pii(c,a));
        adj[a].push_back(pii(c,b));
        //if(c+cost<adj[a][b].A+adj[a][b].B) adj[a][b] = pii(c,cost);
        //if(c+cost<adj[b][a].A+adj[b][a].B) adj[b][a] = pii(c,cost);
    }
    /*for(a = 0;a<pastures;a++){
        //printf("%d\n",adj[1][2].A+adj[1][2].B);
        //printf("%d\n",dist(4,2));
        for(int x = 0;x<pastures;x++){
            for(int y = 0;y<pastures;y++){
                if(x==y) continue;
                int tax = max(adj[x][a].B,adj[a][y].B);
                int costA = adj[x][a].A+adj[a][y].A+tax;
                int costB = adj[x][y].A+adj[x][y].B;
                if(costA<costB){
                    adj[x][y].A = adj[x][a].A+adj[a][y].A;
                    adj[x][y].B = tax; 
                }
                if(costA==costB){
                    if(adj[x][y].B<tax){
                        adj[x][y].A = costA-tax;
                        adj[x][y].B = tax;
                    }
                }
            }
        }
    }*/
    for(int x = 0;x<pastures;x++){
        reset();
        for(int y = 0;y<diff;y++){
            search(x,test[y]);
        }
    }
        
    for(int x = 0;x<queries;x++){
        scanf("%d%d",&a,&b);
        a--;
        b--;
        printf("%lld\n",dist[a][b]+curtax[a][b]);
    }
    
    return 0;
}
