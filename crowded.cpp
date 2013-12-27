#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

#define A first
#define B second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;//first loc then height


priority_queue<pii> q; 


bool left[50500];
bool right[50500];
ll num, dist;
pii loc[50500];

int main(){
    freopen("crowded.in","r",stdin);
    freopen("crowded.out","w",stdout);
    scanf("%lld%lld",&num,&dist);
    ll a,b,temp,temp2;
    for(int x = 0;x<num;x++){
        scanf("%lld%lld",&a,&b);
        loc[x] = pii(a,b);
    }
    sort(loc,loc+num);
    //for(int x = 0;x<num;x++) printf("%d %d\n",loc[x].A,loc[x].B);
    for(int x = 0;x<num;x++){
        temp = loc[x].A;
        temp2 = loc[x].B;
        loc[x].A = temp2;
        loc[x].B = temp;
    }
    for(int x = 0;x<num;x++){
        while(!q.empty()){
            pii cur = q.top();
//            printf("X IS %d TOP IS: %d\n",x,cur.A);
            if(cur.B<loc[x].B-dist){
                q.pop();
                continue;
            }
            if(cur.A>=2*loc[x].A) left[x] = true;
            break;
        }
        q.push(loc[x]);
    }
    while(!q.empty()) q.pop();
    for(int x = num-1;x>=0;x--){
        while(!q.empty()){
            pii cur = q.top();
//            printf("X IS %d TOP IS: %d\n",x,cur.A);
            if(cur.B>loc[x].B+dist){
                q.pop();
                continue;
            }
            if(cur.A>=2*loc[x].A) right[x] = true;
            break;
        }
        q.push(loc[x]);
    }
    ll cnt = 0;
    for(int x = 0;x<num;x++){
        if(left[x]&&right[x]) cnt++; 
    }
    printf("%lld\n",cnt);


    return 0;
}
