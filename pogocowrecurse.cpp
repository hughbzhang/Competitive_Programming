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
vector<int> place;
ll best = 0;
ll dp[MAXN][MAXN];

ll forward(int cur, int past){
    
    int dist = place[cur]-place[past];
    int start = upper_bound(place.begin(),place.end(),place[cur]+dist-1)-place.begin();//start and up is OK
    if(place[num]-place[cur]<dist){
        //its over
        start = num;
    }
    if(start==cur) start++;
    ll record = 0;
    for(int x = start;x<num;x++){
        ll temp  = forward(x,cur);
        if(temp>record) record = temp;
    }
    record+=pnt[cur];
    if(record>best) best = record;
    return dp[cur][past] = record;
}


int main(){
    freopen("pogocow.in","r",stdin);
    scanf("%d",&num);
    int a,b;
    for(int x = 0;x<num;x++){
        scanf("%d%d",&a,&b);
        all.push_back(pii(a,b));
    }
    sort(all.begin(),all.end());
    for(int x = 0;x<num;x++){
        pnt.push_back(all[x].B);
        place.push_back(all[x].A);
    }
    for(int x = 0;x<num;x++){
        forward(x,x);
    }
    for(int y = 0;y<num;y++){
        for(int x = 0;x<num;x++){
            printf("%lld ",dp[y][x]);
        }
        printf("\n");
    }
    printf("%lld\n",best);

    return 0;
}
