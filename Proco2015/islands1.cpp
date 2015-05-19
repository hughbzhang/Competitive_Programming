#include <iostream>

using namespace std;

int dp[11][11][11][4] = {0};
int main() {
	int n; cin >> n;
	dp[1][0][0][1] = 1;
	dp[0][1][0][2] = 1;
	dp[0][0][1][3] = 1;
	dp[1][1][0][1] = 1;
	dp[1][0][1][1] = 1;
	dp[1][1][0][2] = 1;
	dp[0][1][1][2] = 1;
	dp[1][0][1][3] = 1;
	dp[0][1][1][3] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= n; k++) {
				dp[i][j][k][1] = dp[i-1][j][k][2] + dp[i-1][j][k][3];
				dp[i][j][k][2] = dp[i][j-1][k][1] + dp[i][j-1][k][3];
				dp[i][j][k][3] = dp[i][j][k-1][1] + dp[i][j][k-1][2];
			}
		}
	}
	cout << dp[n][n][n][1] + dp[n][n][n][2] + dp[n][n][n][3] << '\n';
	return 0;
}