#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define x first
#define y second

typedef long long ll;
typedef pair<ll, ll> pp;

int N;
pp P1[10100], P2[10100];
int ans = 0;

pp vec(pp p1, pp p2)
{
	return pp(p2.x - p1.x, p2.y - p1.y);
}

int cross(pp p1, pp p2, pp p3)
{
	pp v1 = vec(p1, p2);
	pp v2 = vec(p1, p3);
	ll t = v1.x * v2.y - v2.x * v1.y;
	if(t > 0) return 1;
	if(t < 0) return -1;
	return 0;
}

void check(int i, int j)
{
	int t1 = cross(P1[i], P2[i], P1[j]) * cross(P1[i], P2[i], P2[j]);
	int t2 = cross(P1[j], P2[j], P1[i]) * cross(P1[j], P2[j], P2[i]);
	if(t1 <= 0 && t2 <= 0) ans++;
}

int main()
{
	cin>>N;
	for(int i=0;i<N;i++) cin>>P1[i].x>>P1[i].y>>P2[i].x>>P2[i].y;
	for(int i=0;i<N;i++) for(int j=0;j<i;j++) check(i, j);
	cout<<ans<<endl;
}