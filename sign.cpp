#include <cstdio>

using namespace std;
typedef long long ll;

ll dp[41][41];

ll rec(int y,int x){
    if(y>x||x<0||y<0) return 0;
    if(dp[y][x]!=-1) return dp[y][x];
    return dp[y][x] = rec(y-1,x)+rec(y,x-1);
}

int main(){
    for(int y = 0;y<41;y++){
        for(int x = 0;x<41;x++){
            dp[y][x] = -1;

        }
    }
    dp[0][0] = 1;
    rec(40,40);
    printf("%lld\n",dp[20][20]);
    return 0;
}

