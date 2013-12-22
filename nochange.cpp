#include <cstdio>
#include <vector>
#include <algorithm>

#define MAXN 100100

using namespace std;

typedef long long ll;

vector<ll> sum;
ll coins[20];
int dp[(1<<17)];//1 represents a coin that you have left. 0 indicates you already spent it.
//dp represents how much you can buy with that combination of coins
//so all 1111s is 0

ll numcoins,num;
ll best = -1;


void print(ll in){
    for(int x = 0;x<numcoins;x++){
        if((1<<x)&in) printf("1");
        else printf("0");
    }
    printf("\n");
}

void cost(ll in){
    ll sum = 0;
    for(int x = 0;x<numcoins;x++){
        if((1<<x)&in) sum +=coins[x];
    }
    if(sum>best) best = sum;
}

int recurse(ll in){
    if(dp[in]!=-1) return dp[in];

    for(int x = 0;x<numcoins;x++){
        if(!((1<<x)&in)){
            ll prior = in+(1<<x);
            int pos = upper_bound(sum.begin(),sum.end(),coins[x]+sum[recurse(prior)])-1-sum.begin();  
            if(coins[x]+sum[recurse(prior)]>=sum.back()) pos = num;
            if(pos>dp[in]) dp[in] = pos;
        }
    }
    if(dp[in]==num) cost(in);
    return dp[in];
}

int main(){
    freopen("nochange.in","r",stdin);
    freopen("nochange.out","w",stdout);
    scanf("%lld%lld",&numcoins,&num);
    for(int x = 0;x<numcoins;x++){
        scanf("%lld",coins+x);
    }
    ll a;
    sum.push_back(0);
    for(int x = 0;x<num;x++){
        scanf("%lld",&a);
        sum.push_back(sum.back()+a);
    }
    for(ll x = 0;x<(1<<17);x++) dp[x] = -1;
    dp[(1<<(numcoins))-1] = 0;
    recurse(0);
    printf("%lld\n",best);
    /*for(int x = 0;x<8;x++){
        print(x);
        printf("%d\n\n",dp[x]);
    } */   

    return 0;
}
