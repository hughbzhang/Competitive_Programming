#include <cstdio>
#include <string>
#include <iostream>

using namespace std;
typedef long long ll;

ll C = 0;
ll cur = 0;
int N;
string in;
long long ans = 0;


int main(){
	freopen("cow.in","r",stdin);
	freopen("cow.out","w",stdout);
	cin >> N >> in;
	for(int x = 0;x<N;x++){
		
		if(in.at(x)=='C') C++;
		else if(in.at(x)=='O') cur+=C;
		else ans+=cur;

		
	}
	cout << ans << endl;
}