#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int arr[500] = {0};
int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		arr[(int) s[0]]++;
		arr[(int) s[s.length()-1]]--;
	}
	bool good = true;
	for(int i = 0; i <= 400; i++) {
		if(arr[i] != 0) {
			good = false;
			break;
		}
	}
	if(good) {
		cout << "YES" << '\n';
	}
	if(!good) {
		cout << "NO" << '\n';
		return 0;
	}
}