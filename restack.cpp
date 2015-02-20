#include <cstdio>
#include <iostream>
#define MAX 100100

using namespace std;
typedef long long ll;

int N;
int now[MAX];
int done[MAX];
ll cur[MAX];

ll price(ll s){

    for(int x = 0;x<N;x++) cur[x] = now[x];
    ll cost = abs(s);
    cur[0]+=s;
    cur[N-1]-=s;
    for(int x = 0;x<N;x++){
//        cout << cost << endl;
        cost+=abs(cur[x]-done[x]);
        cur[x+1] += cur[x]-done[x];
        cur[x] = done[x];
    }
    return cost;
}
int main(){
    freopen("restack.in","r",stdin);
    freopen("restack.out","w",stdout);
    cin >> N;
    for(int x = 0;x<N;x++){
        cin >> now[x] >> done[x];
    }
    ll start = -MAX;
    ll top = MAX;
    while(start<top){
        ll mid = start + (top-start)/2;
        ll up = price(mid+1);
        ll down = price(mid);
        if(up<down) start = mid+1;
        else top = mid;
    }
    cout << price(start) << endl;
}



