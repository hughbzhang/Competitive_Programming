#include <cstdio>
#include <algorithm>
#include <cmath>

#define MAXN 100100

using namespace std;
typedef long long ll;

ll num, prices;

ll coins[20];
ll cost[MAXN];
ll money[100000];//hash table for sets (can be rewritten)
ll dp[100000][100100];

ll recurse(ll set, int cur, ll price){
    if(price==0&&dp[set][cur]!=0) return dp[set][cur];
    if(cur==prices){
        if(!price){
            //printf("%lld %d %lld\n",set,cur,price);
            return money[set]; //return the coins you have left if we finish and pay for everything
        }
        else return -1;//failed to pay
    }
    if(!set) return -1;//failed
    price+=cost[cur];
    if(price>coins[num-1]) return -1;//failed
    ll nextset = 0;
    for(int x = 0;x<num;x++){
        if((set&(1<<x))&&coins[x]>=price){
            nextset = set - (1<<x);
            break;
        }
    }
    ll ans = max(recurse(set,cur+1,price),recurse(nextset,cur+1,0));
    if(price==0) dp[set][cur] = ans;
    return ans;
}

int main(){
    freopen("nochange.in","r",stdin);
    freopen("nochange.out","w",stdout);
    scanf("%lld%lld",&num,&prices);
    for(int x = 0;x<num;x++){ scanf("%lld",coins+x); }
    for(int x = 0;x<prices;x++){ scanf("%lld",cost+x);}
    sort(coins,coins+num);
    ll full = (1<<num)-1;
    for(ll x = 0;x<=full;x++){
        for(int a = 0;a<num;a++){
            if(x&(1<<a)) money[x]+=coins[a];
        }
    }
    
    ll ans = recurse(full,0,0);
    printf("%lld\n",ans);
    return 0;
}
