#include <cstdio>

using namespace std;

int num;
int cur;
int dp[100010][2];
int prime = 1000000007;

int main(){
    scanf("%d",&num);
    dp[0][0] = 1;
    dp[0][1] = 0;
    for(int x = 1;x<=num;x++){
        scanf("%d",&cur);
        if(cur%2==0){
            dp[x][0] = (2*dp[x-1][0])%prime;
            dp[x][1] = (2*dp[x-1][1])%prime;
        }
        else{
            dp[x][0] = (dp[x-1][1]+dp[x-1][0])%prime;
            dp[x][1] = (dp[x-1][0]+dp[x-1][1])%prime;
        }
    }
    printf("%d\n",dp[num][0]-1);
    return 0;
}
