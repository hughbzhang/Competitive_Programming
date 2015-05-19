#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;

int N;

ll dp[11][11][11][4];

ll rec(int A, int B, int C,int cur){
	if(A>N||B>N||C>N) return 0;
	if(A==N&&B==N&&C==N) return 1;
	if(cur!=-1&&dp[A][B][C][cur]>0) return dp[A][B][C][cur];
	ll ans = 0;
	if(cur!=0) ans+=rec(A+1,B,C,0);
	if(cur!=1) ans+=rec(A,B+1,C,1);
	if(cur!=2) ans+=rec(A,B,C+1,2);
	if(cur!=-1) return dp[A][B][C][cur] = ans;
	else return ans;
}

int main(){
	cin >> N;

	cout << rec(0,0,0,-1) << endl;
}