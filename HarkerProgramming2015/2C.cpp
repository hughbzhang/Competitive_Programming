#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	long long n;
	long long trial;
	int k;
	int m;
	cin >> m >> k >> n;



	if(((1<<(k-1))&m)==0) {
		if(n < m) {
			cout << 0 << '\n';
		}
		else if(n >= m + (1<<(k-1))) {
			cout << 2 << '\n';
		}
		else cout << 1 << '\n';
	}
	else cout << 0 << '\n';
	return 0;
}