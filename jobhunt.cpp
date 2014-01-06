#include <cstdio>
#include <utility>
#include <vector>

#define A first
#define B second
#define LARGE 1e10

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,pii> piii;

int limit,paths,cities,jets,b;

piii edges[600];
int cnt = 0;
ll dist[250];

int main(){
    freopen("jobhunt.in","r",stdin);
    freopen("jobhunt.out","w",stdout);
    scanf("%d%d%d%d%d",&limit,&paths,&cities,&jets,&b);
    for(int x = 0;x<paths;x++){
        int a,b;
        scanf("%d%d",&a,&b);
        a--;
        b--;
        edges[cnt] = piii(-limit,pii(a,b));
        cnt++;
    } 
    for(int x = 0;x<jets;x++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        a--;
        b--;
        edges[cnt] = piii(c-limit,pii(a,b));
        ++cnt;
    }
    for(int x = 0;x<250;x++) dist[x] = LARGE;
    dist[b-1] = -limit;
    for(int x = 1;x<cities;x++){
        for(int a = 0;a<cnt;a++){
            int cost = edges[a].A;
            int start = edges[a].B.A;
            int dest = edges[a].B.B;
            if(dist[start]+cost<dist[dest]) dist[dest] = dist[start]+cost;
        }
    }
    for(int a = 0;a<cnt;a++){
            int cost = edges[a].A;
            int start = edges[a].B.A;
            int dest = edges[a].B.B;
            if(dist[start]+cost<dist[dest]){
                printf("-1\n");
                return 0;
            }
    }
    ll m = LARGE;
    for(int x = 0;x<cities;x++){
        if(dist[x]<m) m = dist[x];
    }
    printf("%lld\n",-m);

}
