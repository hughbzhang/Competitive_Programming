#include <cstdio>
#include <algorithm>
#include <utility>
#define MAXN 50100
#define A first
#define B second
#define LARGE 99999999999

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

ll num;//number of gas stations
ll full;//max tank
ll start;//how much he starts with
ll total;//total distance

pii stop[MAXN];
ll dp[MAXN];//DP[x] is cost to stop at gas station x
ll rem[MAXN];;//how much fuel you have left at each gas station (usually 0 except for start)


int main(){
    freopen("fuel.in","r",stdin);
    freopen("fuel.out","w",stdout);
    scanf("%lld%lld%lld%lld",&num,&full,&start,&total);
    ll a,b;
    for(int x = 1;x<=num;x++){
        scanf("%lld%lld",&a,&b);
        stop[x] = pii(a,b);
    }
    stop[0] = pii(0,9999999);
    stop[num+1] = pii(total,0);
    num+=2;
    sort(stop,stop+num);
    rem[0] = start;
    ll temp;
    for(int x = 1;x<num;x++) dp[x] = LARGE;
    int cur = 0;//current place
    ll fuel = start;//how much fuel you have
    ll cost = 0;
    int minseen = 0;
    bool flag = true;
    while(cur!=num-1){
        //printf("CUR: %d\nCOST: %lld\nFUEL: %lld\n",cur,cost,fuel);
        flag = true;
        minseen = 0;
        for(int x = cur+1;x<num;x++){
            if(stop[x].A>stop[cur].A+full) break;//farther than i can go
            if(stop[x].B<stop[minseen].B) minseen = x;//minimum gas we have seen so far
            if(stop[x].B<stop[cur].B){
                //go there immediately
                if(fuel>=(stop[x].A-stop[cur].A)){
                //    printf("goo\n");
                    fuel-=(stop[x].A-stop[cur].A);
                    flag = false;
                    cur = x;
                    break;
                }
                else{//buy some fuel
              //      printf("pay\n");
                    cost+=((stop[x].A-stop[cur].A-fuel)*stop[cur].B);
                    fuel = 0;
                    cur = x;
                    flag = false;
                    break;
                }
            }
        }
        if(flag){//we didn't go anywhere
            //printf("buy\n");
            if(minseen == 0){//can't reach destination
                printf("-1\n");
                return 0;
            }
            if(stop[num-1].A<=stop[cur].A+full){//if you can reach end
                cost+=(stop[num-1].A-stop[cur].A)*stop[cur].B;
                break;
            }
            //fill up fuel tank
            cost += (full-fuel)*stop[cur].B;
            fuel = full-stop[minseen].A+stop[cur].A;
            cur = minseen;
        }
    }
    
    printf("%lld\n",cost);
    return 0;
}
