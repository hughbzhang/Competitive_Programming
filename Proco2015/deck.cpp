#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int deck[1010];
set<int> dp[1010];
bool ok[1010];
int N;
vector<int> LOL;


int main(){
	cin >> N;
	for(int x = 0;x<N;x++) cin >> deck[x];
	ok[0] = true;
	for(int x = 1;x<N;x++){
		int best2 = max(deck[x],deck[x-1]);
		int best3 = 0;

		if(x>1) best3 = max(best2,deck[x-2]);
		if(!ok[x-1]) best2 = 0;
		if(x<2||!ok[x-2]) best3 = 0;
		ok[x] = true;
		if(best2==0&&best3==0){
			ok[x] = false;
		}
		else if(best3>best2){
			dp[x] = dp[x-2];
			dp[x].insert(best3);
		}
		else if(best2>best3){
			dp[x] = dp[x-1];
			dp[x].insert(best2);
		}
		else{
			
		}
	
			
		

 	}


	for(int x = N;x<=N;x++){
	 	for(set<int>::iterator it = dp[x-1].begin();it!=dp[x-1].end();++it){
	 		LOL.push_back(*it);
	 	}
	 }
	 reverse(LOL.begin(),LOL.end());
	 for(int x = 0;x<LOL.size();x++) cout << LOL[x] << "\n";



}