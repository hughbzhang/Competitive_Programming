#include <cstdio>
#include <vector>
#define MAXH 210
#define MAX 20200
#define MAXQ 50500
#define LARGE 100000000000
#define A first
#define B second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
typedef vector<piii>::iterator it;
typedef vector<int>::iterator l;

int farms,flights,hubs,orders;

ll out[MAXH][MAX];//from the hubs out
int in[MAXH][MAX];//into the hubs

int hub[MAXH];//list of hubs
int lookup[MAX];//inverse of hub
vector <piii> list;//temp storage of flights
vector <int> indest[MAXH];
vector <int> outdest[MAXH];
ll ans = 0;
ll cant = 0;

int main(){
    freopen("vacationgold.in","r",stdin);
    freopen("vacationgold.out","w",stdout);
    scanf("%d%d%d%d",&farms,&flights,&hubs,&orders);
    int a,b,c;
    for(int x = 0;x<flights;x++){
        scanf("%d%d%d",&a,&b,&c);
        list.push_back(piii(pii(a,b),c));
    }
    for(int x = 0;x<MAX;x++) lookup[x] = -1;
    for(int x = 0;x<hubs;x++){
        scanf("%d",hub+x);
        lookup[hub[x]] = x;
    }
    for(it i = list.begin();i!=list.end();++i){
        piii cur = *i;
        a = cur.A.A;
        b = cur.A.B;
        c = cur.B;
        if(lookup[a]!=-1){
            out[lookup[a]][b] = c;
            outdest[lookup[a]].push_back(b);
        }
        if(lookup[b]!=-1){
            in[lookup[b]][a] = c;
            indest[lookup[b]].push_back(a);
        }
    }
    //floyd warshall
    for(int k = 0;k<hubs;k++){
        for(int y = 0;y<hubs;y++){
            for(int x = 0;x<hubs;x++){
                if(x==y) continue;
                if(out[y][hub[x]]){
                    //if I can go from hub y to hub x
                    //then I can steal all of x's outs too
                    for(l i = outdest[x].begin();i!=outdest[x].end();++i){
                        ll dist = out[x][*i]+out[y][hub[x]];
                        if(out[y][*i]==0) out[y][*i] = dist;
                        else if(dist<out[y][*i]) out[y][*i] = dist;
                    }
                }
                /*if(out[x][hub[y]]){
                    //same the other way;
                    for(l i = outdest[y].begin();i!=outdest[y].end();++i){
                        ll dist = out[y][*i]+out[x][hub[y]];
                        if(out[x][*i]==0) out[x][*i] = dist;
                        else if(dist<out[x][*i]) out[x][*i] = dist;
                    }
                }*/
            }
        }
    }
    //now that we are done calculating outs, lets do the query
    for(int x = 0;x<orders;x++){
        scanf("%d%d",&a,&b);
        ll best = LARGE;
        for(int y = 0;y<hubs;y++){
            if(in[y][a]!=0&&out[y][b]!=0){
                ll pos = in[y][a]+out[y][b];
                if(pos<best) best = pos;
            }
        }
        if(best==LARGE) cant++;
        else ans+=best;   
    }
    printf("%lld\n%lld\n",cant,ans);    

    /*for(int y = 0;y<hubs;y++){
        for(int x = 1;x<=farms;x++){
            printf("%lld ",in[y][x]);
        }
        printf("\n");
    }*/


    return 0;
}
