#include <cstdio>
#include <iostream>
#include <algorithm>


using namespace std;
typedef long long ll;
const int MAX = 100007;


ll dp[MAX][2];
int N;
int arr[MAX];
int cnt[MAX];

int main(){
    scanf("%d",&N);
    for(int x = 0;x<N;x++){
        scanf("%d",&arr[x]);
        cnt[arr[x]]++;
    }
    for(int x = 1;x<MAX;x++){
        dp[x][0]+=dp[x-1][1];
        dp[x][1]+=dp[x-1][0];
        dp[x][1]+=(cnt[x]*(ll)x);
        if(dp[x][1]<dp[x][0]) dp[x][1] = dp[x][0];
    }
    cout << dp[MAX-1][1] << endl;
}
