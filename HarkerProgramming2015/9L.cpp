#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

const int MAXN = 100100;
const int INF = 1e9;

int N, M;
int mini[4*MAXN];
int maxi[4*MAXN];
int lazy[4*MAXN];

void pushdown(int cur)
{
	if(lazy[cur] == 0) return;
	mini[2*cur] += lazy[cur];
	maxi[2*cur] += lazy[cur];
	lazy[2*cur] += lazy[cur];
	mini[2*cur+1] += lazy[cur];
	maxi[2*cur+1] += lazy[cur];
	lazy[2*cur+1] += lazy[cur];
	lazy[cur] = 0;
}

void inc(int left, int right, int cur, int l, int r, int val)
{
	if(l >= right || left >= r) return;
	if(left <= l && r <= right){
		mini[cur] += val;
		maxi[cur] += val;
		lazy[cur] += val;
		return;
	}
	pushdown(cur);
	int mid = (l+r)/2;
	inc(left, right, 2*cur, l, mid, val);
	inc(left, right, 2*cur+1, mid, r, val);
	mini[cur] = min(mini[2*cur], mini[2*cur+1]);
	maxi[cur] = max(maxi[2*cur], maxi[2*cur+1]);
}

int qmax(int left, int right, int cur, int l, int r)
{
	if(left >= r || l >= right) return 0;
	if(left <= l && r <= right){
		return maxi[cur];
	}
	pushdown(cur);
	int mid = (l+r)/2;
	return max(qmax(left, right, 2*cur, l, mid), qmax(left, right, 2*cur+1, mid, r));
}


int qmin(int left, int right, int cur, int l, int r)
{
	if(left >= r || l >= right) return INF;
	if(left <= l && r <= right){
		return mini[cur];
	}
	pushdown(cur);
	int mid = (l+r)/2;
	return min(qmin(left, right, 2*cur, l, mid), qmin(left, right, 2*cur+1, mid, r));
}

int main()
{
	cin>>N>>M;
	for(int i=0;i<M;i++){
		int t, a, b, c;
		cin>>t;
		if(t == 0){
				cin>>a>>b>>c;
				inc(a-1, b, 1, 0, N, c);
		}
		if(t == 1){
			cin>>a>>b;
			cout<<qmax(a-1, b, 1, 0, N) - qmin(a-1, b, 1, 0, N)<<endl;
		}
	}
}