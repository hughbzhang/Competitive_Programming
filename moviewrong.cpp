#include <cstdio>
#include <cmath>


using namespace std;
typedef long long ll;

ll N, L;

ll t[25];
bool vis[25];
ll show[25][1010];
int n[25];
int ans = 25;

void rec(int cur, int slot){
    if(vis[cur]) return;
    vis[cur] = true;
    //printf("%d %d\n",cur,slot);
    
    ll tm = show[cur][slot]+t[cur];
    //printf("%lld\n",tm);
    if(tm>=L){
        int cnt = 0;
        for(int x = 0;x<N;x++){
            if(vis[x]) cnt++;
        }
        if(ans>cnt) ans = cnt;
        return;
    }
    //for(int x = 0;x<N;x++) printf("%d\n",vis[x]);

    for(int x = 0;x<N;x++){
        if(vis[x]) continue;
        for(int a = n[x]-1;a>=0;a--){
            if(tm>=show[x][a]+t[x]) break;
            if(tm>=show[x][a]){
                rec(x,a);
                break;
            }
        }
    }
    vis[cur] = false;
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
        for(int a = 0;a<n[x];a++){
 //           printf("%lld ",show[x][a]);
        }
//        printf("\n");
    }
    for(int x = 0;x<N;x++){
        if(show[x][0]==0){
            rec(x,0);
        }
    }
    if(ans==25) ans = -1;
    printf("%d\n",ans);
//    for(int x = 0;x<N;x++) printf("%d\n",vis[x]);
}


