#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#define MAX (100010)
#define A first
#define B second

using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;

int num;
ll arr[MAX];
ll pre[MAX];//pre[0] = 0
pii sorted[MAX];
ll dp[MAX];
ll prime = (1e9)+9;
ll BIT[MAX];

void add(int in,int num){
    for(int x = in;x<MAX;x+= (x & -x)){
        BIT[x]+=num;
    }
}

ll query(int in){
    ll sum = 0;
    for(int x = in;x>0;x-= (x & -x)){
        sum+=BIT[x];
    }
    return sum;
}



int main(){
    freopen("protest.in","r",stdin);
    freopen("protest.out","w",stdout);
    scanf("%d",&num);
    for(int x = 0;x<num;x++) scanf("%lld",arr+x);
    for(int x = 1;x<=num;x++){
        pre[x] = pre[x-1]+arr[x-1];
    }
    for(int x = 0;x<=num;x++){
        sorted[x] = pii(pre[x],x);
    }
    sorted[num+1] = pii(0,num+1);

    sort(sorted,sorted+num+2);
    for(int x = 0;x<num+2;x++){
        pre[sorted[x].B] = x+1;
    }

    dp[0] = 1;
    add(pre[num+1],dp[0]);
    for(int x = 1;x<=num;x++){
        dp[x] = query(pre[x])%prime;
        add(pre[x],dp[x]);
    }
    printf("%lld\n",dp[num]);
}
