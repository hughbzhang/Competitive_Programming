#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

#define MAX 26000
#define A first
#define B second
#define LARGE 1e15

using namespace std;

typedef long long ll;
typedef pair<ll,int> pii;//dist then dest
typedef pair<int,pii> piii;//planes taken first
typedef vector<pii>::iterator vi;
bool check[MAX];
vector<pii> road[MAX];
vector<pii> plane[MAX];
ll ans[MAX];
int incoming[MAX];
bool vis[MAX];
priority_queue<piii,vector<piii>,greater<piii> > q;
ll tag[MAX];
ll order[MAX];
ll mark = 0;
vector<int> node[MAX];
vector<int> edge[MAX];
ll number = -1;

int num,roads,planes,start;

void fill(int index){
    for(vector<int>::iterator it = node[index].begin();it!=node[index].end();++it){
        int cur = *it;
        for(vi i = plane[cur].begin();i!=plane[cur].end();++i){
            pii next = *i;
            edge[index].push_back(tag[next.B]);
        }
    }
}

void cleanse(int index){
    sort(edge[index].begin(),edge[index].end());
    vector<int>::iterator it = unique (edge[index].begin(), edge[index].end());
    edge[index].resize(distance(edge[index].begin(),it));
    for(vector<int>::iterator it = edge[index].begin();it!=edge[index].end();++it){
        incoming[*it]++; 
    } 
}


void leave(int cur){
    for(vector<int>::iterator it = node[cur].begin();it!=node[cur].end();++it){
        order[*it] = mark;
    }
    mark++;
}

void init(){
    for(int x = 0;x<MAX;x++){
        ans[x] = LARGE;
        tag[x] = -1;
        order[x] = MAX;
    }
    ans[start] = 0;
    tag[start] = 0;
}
/*void find(int cur, int code){
    if(tag[cur]!=-1) return;
    tag[cur] = code;
    for(vi it = road[cur].begin();it!=road[cur].end();++it) leave((*it).B,code);
}*/
void topo(int cur){
    if(vis[cur]) return;
    vis[cur] = true; 
    leave(cur);
    for(vector<int>::iterator it = edge[cur].begin();it!=edge[cur].end();++it){
        incoming[*it]--;
        if(incoming[*it]==0) topo(*it);
    }
}

void group(int start){
    if(vis[start]) printf("REPEAT\n");
    vis[start] = true;
    for(vector<int>::iterator it = edge[start].begin();it!=edge[start].end();++it){
        group(*it);
    }
    leave(start);
    mark--;
    
}
void divide(int cur,int index){
    if(vis[cur]) return;
    vis[cur] = true;
    node[index].push_back(cur);
    tag[cur] = index; 
    for(vi it = road[cur].begin();it!=road[cur].end();++it){
        divide((*it).B,index);
    }
}


void search(){
    for(int x = 0;x<MAX;x++) vis[x] = false;
    q.push(piii(order[start],pii(0,start)));
    while(!q.empty()){
        piii NOW = q.top();
        q.pop();
        ll dist = NOW.B.A;
        int cur = NOW.B.B;

        //printf("CUR = %d\n",cur);
        if(vis[cur]) continue;
        vis[cur] = true;
        for(vi it = road[cur].begin();it!=road[cur].end();++it){
            pii POS = *it;
            ll cost = POS.A;
            int dest = POS.B;

            if(order[dest]!=order[cur]) printf("WRONG %lld %lld\n",order[dest], order[cur]);
            if(cost+dist<ans[dest]){
                ans[dest] = cost+dist;
                q.push(piii(order[dest],pii(cost+dist,dest)));
            }
        }
        for(vi it = plane[cur].begin();it!=plane[cur].end();++it){
            pii POS = *it;
            ll cost = POS.A;
            int dest = POS.B;

            if(order[dest]<=order[cur]) printf("WRONG2 %lld %lld\n",order[dest], order[cur]);
//            assert(order[dest]>order[cur]);
            if(cost+dist<ans[dest]){
                ans[dest] = cost+dist;
                q.push(piii(order[dest],pii(cost+dist,dest)));
            }
        }
    }
    
}

int main(){
    freopen("roadplane.in","r",stdin);
    freopen("roadplane.out","w",stdout);
    scanf("%d%d%d%d",&num,&roads,&planes,&start);
    start--;
    int a,b;
    ll c;
    for(int x = 0;x<roads;x++){
        scanf("%d%d%lld",&a,&b,&c);
        a--;
        b--;
        road[a].push_back(pii(c,b));
        road[b].push_back(pii(c,a));
    }
    for(int x = 0;x<planes;x++){
        scanf("%d%d%lld",&a,&b,&c);
        a--;
        b--;
        plane[a].push_back(pii(c,b));
    }
    init();
    
    for(int x = 0;x<num;x++){
        if(vis[x]==false){
            number++;
            divide(x,number);            
        }
    }


    number++;
    for(int x = 0;x<number;x++){
        fill(x);
        cleanse(x);
    }
    for(int x = 0;x<number;x++) vis[x] = false;
    for(int x = 0;x<number;x++){
        if(incoming[x]==0) topo(x);
    } 
    

    
    /*for(int x = 0;x<number;x++){
        printf("CUR: %d     ",x);
        for(vector<int>::iterator it = edge[x].begin();it!=edge[x].end();++it){
            printf("%d ",*it);
        }
        printf("      IN %d",incoming[x]);
        printf("\n");
    }*/

    search();
    for(int x = 0;x<num;x++){
        if(ans[x]==LARGE) printf("NO PATH\n");
        else printf("%lld\n",ans[x]);
    }
    

    return 0;
}
