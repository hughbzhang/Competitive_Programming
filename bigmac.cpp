#include <cstdio>
#include <utility>
#include <cmath>
#include <limits>
#define MAXN 2020
#define MAXM 25250
#define LARGE (numeric_limits<double>::max())
#define A first
#define B second

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;//start to dest
typedef pair<double, pii> piii;//distance first then start and dest

double coun[MAXN];//list of best prices for each country so far
piii paths[MAXM];


int main(){
    freopen("bigmac.in", "r", stdin);
    freopen("bigmac.out", "w", stdout);
    int countries, edges, start, end;
    double value;
    scanf("%d%d%lf%d%d", &countries, &edges, &value, &start, &end);
    int a,b;
    double c;
    for(int x = 0;x<edges;x++){
        scanf("%d%d%lf", &a, &b, &c);
        paths[x] = piii(c,pii(a,b));//add the edges
    }
    for(int x = 0;x<=countries;x++) coun[x] = LARGE;
    coun[start] = value;
    for(int x = 0;x<countries-1;x++){//maximum shortest path length is countries-1 edges because can only visit each vertex once.
        for(int y = 0;y<edges;y++){
            piii cur = paths[y];
            if(coun[cur.B.A]==LARGE) continue;
            if(coun[cur.B.A]*cur.A<coun[cur.B.B]) coun[cur.B.B] = coun[cur.B.A]*cur.A;
        }
       /* for(a = 0;a<=countries;a++){
            if(coun[a]==LARGE) printf("MAX ");
            else printf("%lf ",coun[a]);
        }
        printf("\n");
       */
    }
    for(int x = 0;x<edges;x++){
        piii cur = paths[x];
        if(coun[cur.B.A]*cur.A<coun[cur.B.B]){
//            printf("%d ", cur.B.A);
            printf("0\n");
            return 0;//negative cycle
        }
    }
    ll answer = (long)floor(coun[end]);
    printf("%lld\n",answer);

    return 0;
}
