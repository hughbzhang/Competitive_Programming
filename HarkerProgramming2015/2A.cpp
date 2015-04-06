#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int a;
	cin >> a;
	bool cool = false;
	for(int i = 2; i <= sqrt(a); i++) {
		if(a % i == 0) {
			cout << a/i << '\n' << i << '\n';
			cool = true;
			break;
		}
	}
	if(!cool) {
		cout << -1 << '\n';
		cout << -1 << '\n';
		return 0;
	}
	return 0;
}


