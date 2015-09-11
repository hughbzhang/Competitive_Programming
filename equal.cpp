#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

const int MAXN = 10010;
int numCases;
int numCoworkers;

int choco[MAXN];

int main(){
	ios::sync_with_stdio(0);
	cin >> numCases;
	for(int t = 0;t<numCases;t++){
		
		cin >> numCoworkers;
		for(int x = 0;x<numCoworkers;x++){
			cin >> choco[x];
		}
		sort(choco,choco+numCoworkers);
		int ans = 1e9;
		for(int x = 0;x<5;x++){

			int past = choco[0]-x;
			int add = 0;
			int operations = x;
			for(int x = 1;x<numCoworkers;x++){
				if(choco[x]+add!=past){
					int newadd = 0;

					while(choco[x]+add>=past+5+newadd){
						newadd+=5;
						operations++;
					}
					while(choco[x]+add>=past+2+newadd){
						newadd+=2;
						operations++;
					}
					while(choco[x]+add>past+newadd){
						newadd++;
						operations++;
					}
					past = choco[x]+add;
					add+=newadd;
				}
			}
			ans = min(ans,operations);
		}
		cout << ans << endl;
	}
	



	return 0;
}