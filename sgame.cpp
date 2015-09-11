#include <cstdio>
#include <iostream>

using namespace std;

int maxn,mishaChoice;

int main(){
	cin >> maxn >> mishaChoice;
	if(maxn==1) cout << 1 << endl;
	else if(mishaChoice-1>=maxn-mishaChoice) cout << mishaChoice-1;
	else cout << mishaChoice+1;
}
