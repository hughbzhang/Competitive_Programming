#include <cstdio>
#include <utility>

#define A first
#define B second
#define LARGE (10000000000)

using namespace std;

const int MAXC = 1010;//max cows
const int MAX = 10100;//max number of constraints

typedef long long ll;
typedef pair<int, int> pii;//start+dest
typedef pair<long, pii> piii;//dist + start/dest
piii paths[3*MAX];
ll dist[MAXC];
int count = 0;


int main(){
    freopen("layout.in", "r", stdin);
    freopen("layout.out", "w", stdout);

    int cows, ML, MD;//ML = at most D apart MD = at least D apart
    scanf("%d%d%d", &cows, &ML, &MD);
    for(int x = 0;x<=cows;x++) dist[x] = LARGE;
    dist[0] = 0; dist[1] = 0;
    int a,b;
    ll c;
    for(int x = 0;x<ML;x++){
        scanf("%d%d%lld", &a,&b,&c);
        paths[count] = piii(c,pii(a,b));
        count++;
    }
    for(int x = 0;x<MD;x++){
        scanf("%d%d%lld", &a,&b,&c);
        paths[count] = piii(-c,pii(b,a));
        count++;
    }
    for(int x = 2;x<=cows;x++){
        paths[count] = piii(0,pii(x,x-1));
        count++;
    }
    
    for(int x = 1;x<cows;x++){
        for(int y = 0;y<count;y++){
            piii cur = paths[y];
            if(dist[cur.B.A]==LARGE) continue;
            if(dist[cur.B.A]+cur.A<dist[cur.B.B]){
                dist[cur.B.B] = dist[cur.B.A]+cur.A;
            }
        }
    }
    for(int x = 0;x<count;x++){
        piii cur = paths[x];
        if(dist[cur.B.A]==LARGE){
            printf("-2\n");//arbitrarily large
            return 0;
        }
        if(dist[cur.B.A]+cur.A<dist[cur.B.B]){
            printf("-1\n");//negative cycle
            return 0;
        }     
    }
    if(dist[cows]==LARGE) printf("-2\n");
    else printf("%lld\n", dist[cows]);

    return 0;
}
