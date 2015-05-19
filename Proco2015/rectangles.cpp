#include <cstdio>
#include <iostream>
#include <utility>
#include <map>

#define A first
#define B second

using namespace std;
typedef pair<int,int> pii;

pii arr[1010];
map<pii,bool> m;
long long cnt = 0;

int N,a,b;

int main(){
	cin >> N;
	for(int x = 0;x<N;x++){
		cin >> a >> b;
		arr[x] = pii(a,b);
		m[arr[x]] = true;
	}
	for(int x = 0;x<N;x++){
		for(int y = x+1;y<N;y++){
			if(arr[x].A==arr[y].A||arr[x].B==arr[y].B) continue;
			if(m[pii(arr[x].A,arr[y].B)]&&m[pii(arr[y].A,arr[x].B)]) cnt++;
		}
	}
	cout << m[pii(0,0)] << endl;
	cout << cnt/2 << endl;
}