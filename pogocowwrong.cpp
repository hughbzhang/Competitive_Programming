#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>
#define MAXN 1010
#define A first
#define B second

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;


int num;
vector<pii> all;
vector<ll> pnt;
vector<ll> place;
ll ans = 0;
ll dp[MAXN][MAXN];
const ll LARGE = 100000000;

//dp[y][x] is the number of points I can make in total by starting at y and jumping to x
//dp[y][x] = pnt[y] + max(dp[x][a]) where a is all places you can jump to
//
//Make the N^3 first

int main(){
    freopen("pogocow.in","r",stdin);
    freopen("pogocow.out","w",stdout);
    scanf("%d",&num);
    int c,b;
    for(int x = 0;x<num;x++){
        scanf("%d%d",&c,&b);
        all.push_back(pii(c,b));
    }
    sort(all.begin(),all.end());
    for(int x = 0;x<num;x++){
        pnt.push_back(all[x].B);
        place.push_back(all[x].A);
    }
    pnt.push_back(0);
    place.push_back(LARGE);

    for(int y = num-1;y>=0;y--){
        for(int x = num;x>y;x--){
            ll best = 0;//best of dp[x][a] where a>x
            for(int a = num;a>x;a--){
                if(place[a]-place[x]<place[x]-place[y]) break;
                if(dp[x][a]>best) best = dp[x][a];
            }
            dp[y][x] = pnt[y]+best;
            if(dp[y][x]>ans) ans = dp[y][x];
        }
    }
    for(int y = 0;y<MAXN;y++){
        for(int x = 0;x<MAXN;x++){
            dp[y][x] = 0;
        }
    }
    
    for(int y = 0;y<num;y++){
        for(int x = 0;x<y;x++){
            ll best = 0;//best of dp[x][a] where a>x
            for(int a = 0;a<x;a++){
                if(place[x]-place[a]<place[y]-place[x]) break;
                if(dp[x][a]>best) best = dp[x][a];
            }
            dp[y][x] = pnt[y]+best;
            if(dp[y][x]>ans){
                printf("CHANGE\n");
                ans = dp[y][x];
            }
        }
    }
    printf("%lld\n",ans);

    return 0;
}
