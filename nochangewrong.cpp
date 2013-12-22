#include <cstdio>
#include <algorithm>

#define MAX (1<<17)

using namespace std;
typedef long long ll;

ll num, prices;

ll coins[20];
ll money[100000];
ll cost[100100];
ll dp[100100];//dp[x] DOES NOT INCLUDE THE PRICE OF X
ll BIT[MAX];

ll query(ll x){
    if(x==0) return 0;
    ll ans = 0;  
    while(x>0){
        ans+=BIT[x];
        x-=(x&-x);
    }
    return ans;
}
void add(ll x, ll val){
    while(x<MAX){
        BIT[x]+=val;
        x+=(x&-x);
    }
}


int search(int coin/*index to the coins*/,int begin/*index to the dp array cur pos*/){//BOTH ARE INDEXES
    int start = 0,end = begin;
    int mid;
    ll total = query(begin);//cost from 0 to begin including begin
    while(start<end){
        mid = start+(end-start)/2;
        if(total-query(mid)>coins[coin]) start=mid+1;//mid DOES NOT WORK
        else end = mid;//mid still might work
    }
    //start should equal end by now
    return start;
}
//goal is to find 


int main(){
    freopen("nochange.in","r",stdin);
    freopen("nochange.out","w",stdout);
    scanf("%lld%lld",&num,&prices);
    for(int x = 0;x<num;x++) scanf("%lld",coins+x);
    for(int x = 0;x<prices;x++){
        scanf("%lld",cost+x); 
        add(x+1,cost[x]);
    }
    ll full = (1<<num)-1;
    sort(coins,coins+num);
    for(ll x = 0;x<=full;x++){
        for(int a = 0;a<num;a++){
            if(x&(1<<a)) money[x]+=coins[a];
        }
    }
    dp[0] = full;
    bool end = true;
    for(int x = 1;x<=prices;x++){
        end = true;
        for(int a = 0;a<num;a++){
            int sep = search(a,x);
            //printf("X: %d SEP: %d COIN: %d\n",x,sep,a);
            if(sep==x) continue;
            if(dp[sep]&(1<<a)){
                ll next = dp[sep]-(1<<a);
                if(money[next]>money[dp[x]]){
                    end = false;
                    dp[x] = next;
                }
            }
        }
        if(end){
            printf("-1\n");
            break;
        }
    }
    for(int x = 0;x<=prices;x++){
        printf("%lld\n",dp[x]);
    }
    printf("%lld\n",money[dp[prices]]);


    return 0;
}
