#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#define A first
#define B second

using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef long long ll;

piii info[30];
ll ans = -1;
ll N,H;
int a,b,c;
pii now[30];
bool use[30];

bool test(ll total,int cnt){
    for(int x = 0;x<cnt;x++){
        if(now[x].B<total) return false;
        total+=now[x].A;
    }
    return true;
}


void check(int cnt){
    if(!test(0,cnt)) return;
    ll s = 0;
    ll e = 20000000000;
    while(s<e){
        ll m = s+(e-s)/2;
        if((e-s)%2==1) m++;
        if(test(m,cnt)) s = m;
        else e = m-1;
    }
    if(s>ans) ans = s;
}


int main(){
    freopen("guard.in","r",stdin);
    freopen("guard.out","w",stdout);
    cin >> N >> H;
    for(int x = 0;x<N;x++){
        cin >> a >> b >> c;
        info[x] = piii(c,pii(a,b)); //strength, height, weight
    }
    sort(info,info+N);
    for(ll x = 0;x<(1<<N);x++){
        bool ok = true;
        ll total = 0;
        ll height = 0;
        int cnt = 0;
        for(int a = 0;a<N;a++){
            if((1<<a)&x){
               now[cnt++] = pii(info[a].B.B,info[a].A);
               height+=info[a].B.A;
            }
        }
        if(height<H) continue;
        sort(now,now+cnt);
        check(cnt);
    }
    if(ans==-1) cout << "Mark is too tall" << endl;
    else cout << ans << endl;
}

