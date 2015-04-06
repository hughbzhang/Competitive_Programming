#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 5100;
const int MAXM = 100100;
const int INF = 1e9;

int pos[MAXN];
int cost[MAXM];
int dp[MAXN];

int N, M;

int main()
{
		cin>>N>>M;
		for(int i=1;i<=N;i++) cin>>pos[i];
		for(int i=1;i<=M;i++) cin>>cost[i];
		sort(pos+1, pos+1+N);
		for(int i=M-1;i>=1;i--) cost[i] = min(cost[i], cost[i+1]);
		dp[1] = cost[1];
		for(int i=2;i<=N;i++) dp[i] = INF;
		for(int i=2;i<=N;i++){
			for(int j=1;j<=i;j++){
				dp[i] = min(dp[i], dp[j-1] + cost[pos[i] - pos[j] + 1]);
			}
		} 
		cout<<dp[N]<<endl;
}