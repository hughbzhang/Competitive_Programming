#include <cstdio>
#include <vector>
#include <utility>

#define A first
#define B second

using namespace std;
typedef pair<int,int> pii; //dest then dist
typedef vector<pii>::iterator vi;
typedef long long ll;

int num;
int cow[100100];
vector<pii> neigh[100100];
int par[100100];
ll sub[100100];


ll DFS(int cur){
    sub[cur]+=cow[cur];
    ll cost = 0;
    for(vi it = neigh[cur].begin();it!=neigh[cur].end();++it){
        int dest = (*it).A;
        int dist = (*it).B;
        if(dest==par[cur]) continue;
        par[dest] = cur;
        cost += DFS(dest);
        cost+=(dist*sub[dest]);
        sub[cur]+=sub[dest];
    }
    return cost;
}


int main(){
    freopen("gather.in","r",stdin);
    freopen("gather.out","w",stdout);
    scanf("%d",&num);
    for(int x = 0;x<num;x++) scanf("%d",cow+x);
    int a,b,c;
    for(int x = 0;x<num-1;x++){
        scanf("%d%d%d",&a,&b,&c);
        a--;
        b--;
        neigh[a].push_back(pii(b,c));
        neigh[b].push_back(pii(a,c));
    }
    ll pos = DFS(0);
    int cur = 0;
    ll total = sub[0];
    bool go = true;
    while(go){
        go = false;
        for(vi it = neigh[cur].begin();it!=neigh[cur].end();++it){
            if((*it).A==par[cur]) continue;
            if(sub[(*it).A]>total-sub[(*it).A]){
                pos-=((sub[(*it).A]-total+sub[(*it).A])*((*it).B));
                cur = (*it).A;
                go = true;
                break;
            }
        }
    }
    printf("%lld\n",pos);

    return 0;
}
