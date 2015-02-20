#include <cstdio>
#include <algorithm>
#include <cmath>

#define ALL (1<<11)+1

using namespace std;
typedef long long ll;

ll N, L;

ll t[25];
//bool dp[25][1010][ALL];
bool vis[25][1010][ALL];
ll show[25][1010];
int n[25];
int ans = 25;
ll best[ALL];

void rec(int cur, int slot, ll past){
    if(vis[cur][slot][past]) return;
    vis[cur][slot][past] = true;
    ll tm = show[cur][slot]+t[cur];
    if(tm>=L){
        int cnt = 0;
        for(int x = 0;x<N;x++){
            if((1<<x)&past) cnt++;
        }
        if(ans>cnt) ans = cnt;
        return;
    }
    if(best[past]>=tm) return;
    best[past] = max(best[past],tm);
    for(int x = 0;x<N;x++){
        if(!((1<<x)&past)){
            if(show[x][0]>tm) continue;
            //if(show[x][0]==tm) rec(x,0,past+(1<<x));
            else{
                ll* next = lower_bound(show[x],show[x]+n[x],tm);
                if(*next>tm) next--;
                rec(x,next-show[x],past+(1<<x));
                //printf("%d\n",next-show[x]);
            }
            //printf("%lld %lld %lld\n",*next,tm,*(next+1));
            /*for(int a = 0;a<n[x];a++){
                if(tm>=show[x][a]&&tm<show[x][a]+t[x]){
                    rec(x,a,past+(1<<x));
                }
            }*/
        }
    }
}

    

int main(){
    freopen("movie.in","r",stdin);
    freopen("movie.out","w",stdout);
    scanf("%lld%lld",&N,&L);
    for(int x = 0;x<N;x++){
        scanf("%lld",&t[x]);
        scanf("%d",&n[x]);
        for(int a = 0;a<n[x];a++){
            scanf("%lld",&show[x][a]);
        }
    }
    for(int x = 0;x<N;x++){
        if(show[x][0]==0){
            rec(x,0,(1<<x));
        }
    }
    if(ans==25) ans = -1;
    printf("%d\n",ans);
}


