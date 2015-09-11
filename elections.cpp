#include <cstdio>
#include <iostream>

using namespace std;

int candidates, cities;
int candidateCityWin[110];

int main(){
	ios::sync_with_stdio(0);
	cin >> candidates >> cities;
	for(int x = 0;x<cities;x++){
		int most = -1;
		int winner = -1;
		for(int y = 0;y<candidates;y++){
			int vote;
			cin >> vote;
			if(vote>most){
				most = vote;
				winner = y;
			}
		}
		candidateCityWin[winner]++;
	}
	int overallWinner = -1;
	int most = -1;
	for(int x = 0;x<candidates;x++){
		if(candidateCityWin[x]>most){
			overallWinner = x;
			most = candidateCityWin[x];
		}
	}
	cout << overallWinner+1 << endl;
}