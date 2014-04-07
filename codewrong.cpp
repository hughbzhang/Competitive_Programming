#include <cstdio>
#include <cmath>
#include <map>
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#define A first
#define B second

using namespace std;
typedef pair<int,string> pii;
typedef long long ll;
typedef long double ld;
int par[23000];

map<pii,int> all;
map<pii,bool> vis;

int N,M;
ll ans = 0;
vector<pii> list;
ll ten[7];
ll mod = 1234567;

ll choose(ll in, ll x){
    if(x>in-1) return 0;
    ld done = 1;
    for(int a = 0;a<x;a++){
        done*=(in-a);
        done/=(x-a);
    }
    return ((ll)round(done))%mod;
}

void cnt(int in){
    bool add = true;
    if(in%2==0) add = false;
    int pow = N-5-in+1;
    for(int x = 0;x<7;x++){
        if(pow>6) break;
        if(add) ans+=((choose(in,x)*ten[pow])%mod);
        else ans-=((choose(in,x)*ten[pow])%mod);
        ans%=mod;
        add = !add;
        pow++;
    }
}


void search(int cur, string now){
    if(now.length()==0) return;
    pii NOW = pii(cur,now);
    if(now.length()==5&&all[NOW]>0) return;
    all[NOW]++;
    if(all[NOW]>1){
        if(all[NOW]==2) list.push_back(NOW);
        return;
    }
    now.erase(now.begin(),now.begin()+1);
    search(par[cur],now);
}

int main(){
    ten[0] = 1;
    for(int x = 1;x<7;x++) ten[x] = ten[x-1]*10;
    
    ios::sync_with_stdio(0);
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    cin >> N >> M;
    int cur;
    string in;
    for(int x = 1;x<N;x++){
        cin >> par[x];
    }
    for(int x = 0;x<M;x++){
        cin >> cur >> in;
        search(cur,in);
    }
    for(int x = 0;x<list.size();x++){
        cnt(all[list[x]]);
    }
    cout << ans%mod << endl;
}
