#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int par[200];
vector<int> child[200];
int val[200];
int sum[200];
int num[200];
int N;
double best = 0;

void rec(int cur){

	sum[cur] = val[cur];
	num[cur] = 1;
	for(int x = 0;x<child[cur].size();x++){
		rec(child[cur][x]);
		sum[cur]+=sum[child[cur][x]];
		num[cur]+=num[child[cur][x]];
	}
	//cout << cur << " " << sum[cur] << " " << num[cur] << endl;
	if((sum[cur]/(double)num[cur])>best) best = sum[cur]/(double)num[cur];
}

int main(){
	cin >> N;
	for(int x = 1;x<=N;x++){
		cin >> par[x] >> val[x];
		child[par[x]].push_back(x);
	}
	rec(1);
	cout << fixed << setprecision(3) << best << endl;
}