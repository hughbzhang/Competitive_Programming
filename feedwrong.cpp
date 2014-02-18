#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>
#define A first
#define B second

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;//store, then num
typedef pair<ll,pii > piii;//cost then index

int total, done, num;
ll ans = 0;
priority_queue<piii,vector<piii>, greater<piii> > q;

int cost[510];//cost of feed at each store
int dist[510];//dist of each stroe
int pile[510];//stockpile of each store

int main(){
    freopen("feed.in","r",stdin);
    scanf("%d%d%d",&total,&done,&num);
    for(int x = 0;x<num;x++){
        scanf("%d%d%d",&dist[x],&pile[x],&cost[x]);
        dist[x] = done-dist[x];
        q.push(piii(cost[x]+dist[x],pii(x,1)));
    }
    for(int x = 0;x<total;x++){
        piii cur = q.top();
        q.pop();
        ll price = cur.A;
        int store = cur.B.A;
        int number = cur.B.B;
        ans+=price;
        if(number<pile[store]){
            number++;
            q.push(piii(cost[store]+number*number*dist[store]-price,pii(store,number)));
        }
        printf("%lld %d %d\n",price,store,number);
    }
    printf("%lld\n",ans);

    return 0;
}
