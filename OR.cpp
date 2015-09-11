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
			if(!(low&oneBit)){
				//high has and low doesnt so we are done and fill everything with ones
				//b/c oneBit-1 has to occur somewhere here
				ans |= (oneBit|(oneBit-1));
				break;
			}
			else{//both have ones so you add it to ans
				ans |= oneBit;
			}

		}
		cout << ans << endl;
	}
}