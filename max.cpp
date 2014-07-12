#include <cstdio>
#include <iostream>

using namespace std;
int N;
int ans = -1000;
int arr[104][104];
int dp[104][104][104];
int sum[104][104];

void print(){
    for(int y = 0;y<N;y++){
        for(int x = 0;x<N;x++){
            for(int a = 0;a<N;a++){
                cout << dp[y][x][a] << " ";
            }
        }
        cout << endl;
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    cin >> N;
    for(int y = 0;y<N;y++){
        for(int x = 0;x<N;x++){
            cin >> arr[y][x];
            ans = max(ans,arr[y][x]);
        }
    }
    
    for(int y = 0;y<N;y++) for(int x = 1;x<=N;x++) sum[y][x] = sum[y][x-1]+arr[y][x-1];
    for(int a = 0;a<N;a++){
        for(int b = a+1;b<N;b++){
            dp[0][a][b] = max(sum[0][b+1]-sum[0][a],0);
        }
    }
    for(int y = 1;y<N;y++){
        for(int a = 0;a<N;a++){
            for(int b = a+1;b<N;b++){
                dp[y][a][b] = max(dp[y-1][a][b]+sum[y][b+1]-sum[y][a],0);
                if(ans>0) ans = max(ans,dp[y][a][b]);
            }
        }
    }
    /*for(int y = 0;y<N;y++){
        for(int x = 0;x<=N;x++){
            cout << sum[y][x] << " ";
        }
        cout << endl;
    }*/

    
    cout << ans << endl;
}
