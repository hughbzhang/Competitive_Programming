#include <cstdio>
#include <utility>
#define MAXN 100100
#define A first
#define B second

using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;

pii deque[MAXN];
int start = 0;
int end = -1;

void add(ll next,int index){
    while(end>=start&&next>deque[end].A) end--;
    end++;
    deque[end] = pii(next,index);
}
ll best(int begin){//start is first index allowed
    while(begin>deque[start].B) start++;
    return deque[start].A;
}
ll total;
int cows,block;
ll val[MAXN];
ll dp[MAXN];

int main(){
    freopen("mowlawn.in","r",stdin);
    freopen("mowlawn.out","w",stdout);
    scanf("%d%d",&cows,&block);
    block++;
    for(int x = 1;x<=cows;x++){
        scanf("%lld",val+x);
        total+=val[x];
    }
    val[0] = 0;
    val[cows+1] = 0;
    add(0,0);
    for(int x = 1;x<block;x++){
        dp[x] = -val[x];
        add(dp[x],x);
    }
    for(int x = block;x<=cows+1;x++){
        dp[x] = best(x-block)-val[x];
        add(dp[x],x);
    }
    /*for(int x = 0;x<=cows+1;x++){
        printf("%d\n",dp[x]);
    }*/
    printf("%lld\n",dp[cows+1]+total);
}
