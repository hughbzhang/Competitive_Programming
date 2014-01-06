#include <cstdio>
#include <vector>
#include <set>
#include <utility>

#define A first
#define B second

using namespace std;
typedef pair<int,int> pii;//destination then distance


int pastures,paths,routes;
vector<pii> adj[1010];
multiset<int> dist[1010];

int m(int index){
    multiset<int>::iterator it = dist[index].end();
    --it;
    return *it;
}
void t(int index){
    if(dist[index].size()<=routes) return;
    multiset<int>::iterator past = dist[index].end();
    multiset<int>::iterator cur = dist[index].end();
    --cur;

    while(dist[index].size()>routes){
        dist[index].erase(past);
        past = cur;
        --cur;
    }
}

int main(){
    freopen("cowjog.in","r",stdin);
    freopen("cowjog.out","w",stdout);
    scanf("%d%d%d",&pastures,&paths,&routes);
    
    int a,b,c;
    for(int x = 0;x<paths;x++){
        scanf("%d%d%d",&a,&b,&c);
        adj[a].push_back(pii(b,c));
    }
    dist[pastures].insert(0);
    for(int cur = pastures;cur>1;cur--){
        if(dist[cur].size()>routes){
            int size = dist[cur].size()-routes;
            multiset<int>::iterator start = dist[cur].end();
            for(int x = 0;x<size;x++) --start;
            dist[cur].erase(start,dist[cur].end());
        }
        //t(cur); 
        for(vector<pii>::iterator it = adj[cur].begin();it!=adj[cur].end();++it){
            multiset<int>::iterator iter = dist[cur].begin();
            multiset<int>::iterator END = dist[cur].end();
            pii edge = *it;
            int dest = edge.A;
            int cost = edge.B;
            while(iter!=END){
                if(dist[dest].size()>routes&&(*iter+cost)>m(dest)) break;
                dist[dest].insert(*iter+cost);
                ++iter;
            }
        }
    }
    multiset<int>::iterator iter = dist[1].begin();
    multiset<int>::iterator END = dist[1].end();
    int cnt = 0;
    while(iter!=END){
        printf("%d\n",*iter);
        ++iter;
        ++cnt;
        if(cnt==routes) break;
    }
    for(int x = cnt;x<routes;x++){
        printf("-1\n");
    }

    

    return 0;
}

