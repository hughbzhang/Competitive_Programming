#include <cstdio>
#include <algorithm>
#include <utility>
#define MAX 1010
#define LARGE (1e7)
#define A first
#define B second

using namespace std;
typedef long long ll;
typedef pair<int,ll> pii;

int num;

pii list[MAX];
ll dp[MAX][MAX];
ll ans = 0;


void calc(){
    for(int y = num-1;y>=0;y--){
        int start = num;
        ll best = 0;
        for(int x = 0;x<=y;x++){
            while(start>y&&list[start].A-list[y].A>=list[y].A-list[x].A){
                if(dp[start][y]>best) best = dp[start][y];
                start--;
            }
            dp[y][x] = best+list[y].B;
        }
        if(dp[y][y]>ans) ans = dp[y][y];
    }
}

int main(){
    freopen("pogocow.in","r",stdin);
    freopen("pogocow.out","w",stdout);
    scanf("%d",&num);
    int a,b;
    for(int x = 1;x<=num;x++){
        scanf("%d%d",&a,&b);
        list[x] = pii(a,b);
    }
    sort(list+1,list+num+1);
    list[0] = pii(-LARGE,0);
    list[num+1] = pii(LARGE,0);
    for(int y = num;y>0;y--){
        int start = num+1;
        ll best = 0;
        for(int x = 0;x<=y;x++){
            while(start>y&&list[start].A-list[y].A>=list[y].A-list[x].A){
                if(dp[start][y]>best) best = dp[start][y];
                start--;
            }
            dp[y][x] = best+list[y].B;
        }
        if(dp[y][y]>ans) ans = dp[y][y];
    }
    
    for(int y = 1;y<=num;y++){
        int start = 0;
        ll best = 0;
        for(int x = num;x>=y;x--){
            while(start<y&&list[y].A-list[start].A>=list[x].A-list[y].A){
                if(dp[start][y]>best) best = dp[start][y];
                start++;
            }
            dp[y][x] = best+list[y].B;
        }
        if(dp[y][y]>ans) ans = dp[y][y];
    }

    /*for(int y = 0;y<num;y++){
        for(int x = 0;x<=y;x++){
            printf("%lld ",dp[y][x]);
        }
        printf("\n");
    }*/
    printf("%lld\n",ans);



}
