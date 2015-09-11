#include <iostream>
#include <cstdio>

using namespace std;

unsigned int all;
int numCases;

int main(){
	cin >> numCases;
	for(int x = 0;x<numCases;x++){
		cin >> all;
		cout << ~all << endl;
	}
}