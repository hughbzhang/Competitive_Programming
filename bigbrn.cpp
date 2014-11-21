/*
ID:bigfish2
LANG:C++
TASK:bigbrn
*/
#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;
bool vis[1010][1010];
int dp[1010][1010];
int N,T,a,b;
int ans = 0;

int m(int a,int b, int c){
    return min(min(a,b),c);
}

int main(){
    freopen("bigbrn.in","r",stdin);
    freopen("bigbrn.out","w",stdout);
    cin >> N >> T;
    for(int x = 0;x<T;x++){
        cin >> a >> b;
        a--;
        b--;
        vis[a][b] = true;
    }
    for(int x = 0;x<N;x++){
        if(!vis[x][0]) dp[x][0] = 1;
        if(!vis[0][x]) dp[0][x] = 1;
    }
    for(int x = 1;x<N;x++){
        for(int y = 1;y<N;y++){
            dp[y][x] = m(dp[y][x-1],dp[y-1][x-1],dp[y-1][x])+1;
            if(vis[y][x]) dp[y][x] = 0;
        }
    }
    for(int y = 0;y<N;y++) for(int x = 0;x<N;x++) if(ans<dp[y][x]) ans = dp[y][x];
    cout << ans << endl;
}
