#include <cstdio>
#include <iostream>

#define MAXN 100100
#define LARGE 1000000000000
#define MAXH 110

using namespace std;
typedef long long ll;

int top = 0;
ll dp[2][MAXH];
ll q[MAXH];
int num[MAXH];
int h[MAXN];
int N,C;
int f = 0;
int b = -1;
ll ans = LARGE;




int main(){
    freopen("telewire.in","r",stdin);
    freopen("telewire.out","w",stdout);
    cin >> N >> C;
    for(int x = 0;x<N;x++){
        cin >> h[x];
        top = max(h[x]+1,top);
    }
    for(int x = 0;x<MAXH;x++){
        if(x<h[0]) dp[0][x] = LARGE;
        else dp[0][x] = (x-h[0])*(x-h[0]);
    }


    //print();
    for(int y = 1;y<N;y++){
        for(int x = 0;x<MAXH;x++){
            if(x<h[y]) dp[y%2][x] = LARGE;
            else dp[y%2][x] = (x-h[y])*(x-h[y]);
        }

        f = 0;
        b = -1;
        ll bot = LARGE;
        for(int x = 0;x<=h[y];x++){
            if(dp[(y+1)%2][x]+(h[y]-x)*C<bot) bot = dp[(y+1)%2][x]+(h[y]-x)*C;
        }
        for(int x = h[y]+1;x<top;x++){

            ll cost = dp[(y+1)%2][x]+(x-h[y])*C;
            while(b>=f&&q[b]>=cost) b--;
            b++;
            q[b] = cost;
            num[b] = x;
        }
        b++;
        q[b] = LARGE;
        num[b] = top;
        ll penalty = -C;
        for(int x = h[y];x<top;x++){
            penalty+=C;
            if(num[f]==x){
                if(q[f]-penalty<bot+penalty) bot = q[f]-2*penalty; 
                f++;
            }
            //cout << dp[y][x] << " ";
            dp[y%2][x] += min(bot+penalty,q[f]-penalty);
            //cout << dp[y][x] << endl;
        }
    }
    for(int x = 0;x<top;x++){
        ans = min(ans,dp[(N-1)%2][x]);
    }
    cout << ans << endl;
}
