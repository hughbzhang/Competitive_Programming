#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

const int MAXN = 100100;
const int MAXV = 1e9+100;
pair<int,int> bales[MAXN]; // position then size
int numBales,bessiePosition;
int ans = MAXV;

int main(){

	freopen("trapped.in","r",stdin);
	freopen("trapped.out","w",stdout);


	ios::sync_with_stdio(0);
	cin >> numBales >> bessiePosition;
	for(int x = 0;x<numBales;x++){
		int a,b;
		cin >> a >> b;//a is size, b is position
		bales[x] = make_pair(b,a);
	}

	sort(bales,bales+numBales);
	int low = lower_bound(bales,bales+numBales,make_pair(bessiePosition,0))-bales-1;
	//index of the bale directly to bessie's left
	int high = upper_bound(bales,bales+numBales,make_pair(bessiePosition,0))-bales;
	//index of the position directly to bessie's right
	if(bessiePosition<=bales[low].first||bessiePosition>=bales[high].first){
		cout << "-1\n";
		return 0;
		//edge cases of when bessie is past the last bale
	}

	int highReached = high;
	for(int x = low;x>=0;x--){
		while(highReached<numBales&&bales[highReached].first-bales[x].first>bales[highReached].second)
			highReached++;	
		
		if(highReached>=numBales) break;
		ans = min(ans,max(0,bales[highReached].first-bales[x].first-bales[x].second));
	}
	int lowReached = low;
	for(int x = high;x<numBales;x++){
		while(lowReached>=0&&bales[x].first-bales[lowReached].first>bales[lowReached].second)
			lowReached--;
		
		if(lowReached<0) break;
		ans = min(ans,max(0,bales[x].first-bales[lowReached].first-bales[x].second));
	}
	if(ans==MAXV) ans = -1;
	cout << ans << endl;


}