#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pp;

const int MAXN = 100100;
const ll INF = 0x3FFFFFFFFFFFFFFLL;

vector<pp> node[MAXN];
int N, M;

int visited[MAXN][2];
ll dist[MAXN][2];

ll dij()
{
	priority_queue<pp, vector<pp>, greater<pp> > PQ;
	for(int i=1;i<=N;i++) dist[i][0] = dist[i][1] = INF;
	dist[1][0] = 0;
	PQ.push(pp(0, 2));
	while(!PQ.empty()){
		pp temp = PQ.top();
		int cur = temp.second / 2;
		int type = temp.second % 2;
		PQ.pop();
		if(visited[cur][type]) continue;
		visited[cur][type] = 1;
		for(int i=0;i<node[cur].size();i++){
			int ch = node[cur][i].second;
			ll len = node[cur][i].first;
			if(dist[ch][type] > dist[cur][type] + len){
				dist[ch][type] = dist[cur][type] + len;
				PQ.push(pp(dist[ch][type], 2*ch+type));
			}
			if(type == 0 && dist[ch][1] > dist[cur][0] + len / 2){
				dist[ch][1] = dist[cur][0] + len/2;
				PQ.push(pp(dist[ch][1], 2*ch+1));
			}
		}
	}
	return min(dist[N][0], dist[N][1]);
}

int main()
{
		cin>>N>>M;
		for(int i=0;i<M;i++){
				int a, b;
				ll c;
				cin>>a>>b>>c;
				node[a].push_back(pp(c,b));
				node[b].push_back(pp(c,a));
		}
		cout<<dij()<<endl;
}