#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pp;

const int MAXN = 100100;

vector<pp> node[MAXN];

int N, M;
ll dist[MAXN];

void dfs(int cur, int par)
{
	for(int i=0;i<node[cur].size();i++){
		int ch = node[cur][i].first;
		ll len = node[cur][i].second;
		if(ch == par) continue;
		dist[ch] = dist[cur] + len;
		dfs(ch, cur);
	}
}

int main()
{
	cin>>N>>M;
	for(int i=0;i<M;i++){
		int a, b;
		ll c;
		cin>>a>>b>>c;
		node[a].push_back(pp(b,c));
		node[b].push_back(pp(a,c));
	}
	dfs(1, -1);
	int best;
	ll maxi = 0;
	for(int i=1;i<=N;i++) if(dist[i] > maxi){
			maxi = dist[i];
			best = i;
		}
	dist[best] = 0;
	dfs(best, -1);
	for(int i=1;i<=N;i++) maxi = max(maxi, dist[i]);
	cout<<maxi<<endl;
	
}