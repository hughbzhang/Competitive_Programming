#include <cstdio>
#include <iostream>

using namespace std;
int sum = 0;
int a,N;
int arr[100100];

int main(){
	cin >> N;
	for(int x = 0;x<N;x++){
		cin >> arr[x];
		sum = sum^arr[x];
	}
	int cur = 0;
	for(int x = 0;x<N-1;x++){
		cin >> a;
		cur = cur^a;
	}
	cout << (sum^cur) << endl;
	sum = cur;
	cur = 0;
	for(int x = 0;x<N-2;x++){
		cin >> a;
		cur = cur^a;
	}
	cout << (sum^cur) << endl;
}