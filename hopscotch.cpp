#include <cstdio>
#include <iostream>

using namespace std;
typedef long long ll;

int R,C,K;

ll dp[800][800];
int grid[800][800];
ll sum[751][751][750*750+1];
ll prm = 1e9+7;

int main(){
    ios::sync_with_stdio(0);
    freopen("hopscotch.in","r",stdin);
    //freopen("hopscotch.out","w",stdout);
    cin >> R >> C >> K;
    for(int y = 0;y<R;y++){
        for(int x = 0;x<C;x++){
            cin >> grid[y][x];
        }
    }
    dp[R-1][C-1] = 1;
    sum[R-1][C-1][grid[R-1][C-1]] = 1;
    sum[R-1][C-1][0] = 1;
    for(int y = R-1;y>=0;y--){
        for(int x = C-1;x>=0;x--){
            for(int a = 0;a<K;a++){
                sum[y][x][a] = sum[y+1][x][a]+sum[y][x+1][a]-sum[y+1][x+1][a];
                if(grid[y][x]==a) sum[y][x][a]++;
                sum[y][x][0]+=sum[y][x][a];
            }
            dp[y][x] += sum[y+1][x+1][0]-sum[y+1][x+1][grid[y][x]];
        }
    }
    for(int y = 0;y<R;y++){
        for(int x = 0;x<C;x++){
            cout << sum[y][x][1] << " ";
        }
        cout << endl;
    }
    cout << dp[0][0] << endl;
}



