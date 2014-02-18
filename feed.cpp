#include <cstdio>
#include <utility>
#include <algorithm>

#define A first
#define B second
#define LARGE (1e13)

using namespace std;
typedef long long ll;
typedef pair<int,ll> pii;//num then cost
typedef pair<int,pii > piii;//dist the pii

int total,done,num;

piii list[510];
pii q[10010];
int start = 0, last = 0;
int dist[10010];
int limit[10010];
ll cost[10010];
ll dp[2][10010];

int main(){
    freopen("feed.in","r",stdin);
    freopen("feed.out","w",stdout);
    scanf("%d%d%d",&total,&done,&num);
    for(int x = 0;x<num;x++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        list[x] = piii(a,pii(b,c));
    }
    sort(list,list+num);
    list[num] = piii(done,pii(10001,LARGE));
    for(int x = 0;x<=num;x++){
        dist[x] = list[x].A;
        limit[x] = list[x].B.A;
        cost[x] = list[x].B.B;
    }
    for(int x = total-1;x>=0;x--){
        dp[num%2][x] = dp[num%2][x+1]+LARGE;
    }
    for(int x = num-1;x>=0;x--){
        dp[x%2][total] = dp[(x+1)%2][total]+total*total*(dist[x+1]-dist[x]);
        start = 0;
        last = 1;
        q[0] = pii(total,dp[x%2][total]);
        for(int y = total-1;y>=0;y--){
            while(start<last&&q[start].A-y>limit[x]) start++;
            ll go = dp[(x+1)%2][y]+y*y*(dist[x+1]-dist[x]);
//            dp[x%2][y] = min(q[start].B+cost[x]*(q[start].A-y),go);
            while(start<last&&go-cost[x]*(q[last-1].A-y)<=q[last-1].B) last--;
            q[last] = pii(y,go);
            last++;
            dp[x%2][y] = q[start].B+cost[x]*(q[start].A-y);
        }
    }
    /*for(int y = 0;y<=num;y++){
        for(int x = 0;x<=total;x++){
            printf("%lld ",dp[y][x]);
        }
        printf("\n");
    }
    printf("\n");
    for(int x = 0;x<num;x++){
        printf("%d %d %lld\n",dist[x],limit[x],cost[x]);
    }*/

    printf("%lld\n",dp[0][0]);

    return 0;
}
