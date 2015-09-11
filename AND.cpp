#include <cstdio>
#include <iostream>

using namespace std;

int numCases;
unsigned int low, high;
unsigned int ans;

int main(){
	cin >> numCases;
	for(int t = 0;t<numCases;t++){
		cin >> low >> high;
		ans = 0;
		for(int x = 0;x<32;x++){
			unsigned int oneBit = (1<<(31-x));
			if(!(high&oneBit)) continue;
			//at this point we know high as a 1 in this bit
			
			if(low&oneBit) ans |= oneBit; //both have ones so you add it to ans
			else break; //otherwise we are done
			

		}
		cout << ans << endl;
	}
}