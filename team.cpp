#include <cstdio>
#include <iostream>

using namespace std;
int ans = 0;
int N,M;

int main(){
	cin >> N >> M;
	if(N<M){
		int temp = N;
		N = M;
		M = temp;
	}
	if(N>=2*M){
		cout << M << endl;
		return 0;
	}
	else{
		cout << N-M+(4*M-2*N)/3 << endl;
		return 0;
	}







}