#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;

ll dp[2020][2020];

//dp[a][b] means number of sequences at position a with item b
//dp[a][b]


int N,K;
//N is max num
//K is length
ll ans = 0;
ll prime = 1000000007;
vector<int> fact[2020];



int main(){
    scanf("%d%d",&N,&K);
    for(int x = 0;x<=N;x++) dp[1][x] = 1;
    for(int x = 1;x<=N;x++){
        for(int a = 1;a<=x;a++){
            if(x%a==0) fact[x].push_back(a);
        }
    }
    for(int y = 2;y<=K;y++){
        for(int x = 1;x<=N;x++){
            for(int a = 0;a<fact[x].size();a++){
                dp[y][x]+=dp[y-1][fact[x][a]];
                dp[y][x]%=prime;
            }
        }
    }
    for(int x = 1;x<=N;x++){
        ans+=dp[K][x];
        ans%=prime;
    }
    for(int y = 0;y<=N;y++){
        for(int x = 0;x<=K;x++){
        }
    }
    cout << ans << endl;

}
