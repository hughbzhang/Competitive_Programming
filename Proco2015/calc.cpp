#include <iostream>

using namespace std;

int arr[100010];
int main() {
	 arr[0] = 0; int n; cin >> n;
	for(int i = 1; i <= n; i++) {
		char c; cin >> c;
		if(c == '+') {
			arr[i] = arr[i-1] + 1;
		}
		if(c == '-') {
			arr[i] = arr[i-1] - 1;
		}
		if(c == 'z') {
			int k; cin >> k;
			arr[i] = arr[i-k-1];
		}
	}
	cout << arr[n] << '\n';
	return 0;
}