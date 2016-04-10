#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <bitset>

using namespace std;
typedef unsigned long long int ll;

int length, numCoins, junk;
int solutions = 0;

ll add;

ll ans[15];

map<ll,bool> sieve;
vector<ll> primes;

void findSieve() {
	ll stop = (ll)pow(10, length/2-1);
	sieve[0] = true;
	cout << stop << endl;

    for(ll x = 1;x<stop;x++){
        if(sieve[x]==false){ //we are prime
            int square = 2*x*(x+1);//(2x+1)^2 => 4x^2+4x+1 => 2[2*x*(x+1)]+1
            int val = 2*x+1;
            cout << square;
            for(int a = square;a<stop;a+=val){
                sieve[a] = true;//we are composite
            }
        }
        if ((x%10000)==0) cout <<"JI";
    }
    primes.push_back(2);
    for(int x = 0;x<stop;x++) if(!sieve[x]) primes.push_back(2*x+1);
}

ll divisor(ll cur) {
	for (int x = 0;x < primes.size();x++) {
		if (primes[x] > sqrt(cur)+1) break;
		if ((cur%primes[x])==0) return primes[x];
	}
	return 1;
}

ll convertFromBase(ll cur, int base) {
	ll multiply = 1;
	ll converted = 0;
	for (int x = 0; x < length; x++) {
		if ((1<<x)&cur) {
			converted += multiply;
		}
		multiply *= base;
	}
	return converted;
}

void printAns(ll cur) {

	for (int x = 0; x<length;x++) {
		if((1<<x)&cur) cout << 1;
		else cout << 0;
	}

	for (int x = 2; x<11;x++) {
		cout << " " << ans[x];
	}
	cout << endl;
	//solutions++;

}

void check(ll cur) {
	for (int x = 2; x<11;x++) {
		ll baseChanged = convertFromBase(cur, x);
		ll foundOne = divisor(baseChanged);
		//cout << foundOne << endl;
		if (foundOne == 1) return;
		ans[x] = foundOne;
	}

	printAns(cur);
	return;
}

int main() {
	cin >> junk >> length >> numCoins;
	cout << "Case #1:" << endl;
	findSieve();


	for(int x = 0;x<primes.size();x++) cout << primes[x] << endl;
	//return 0;
	add = (1<<(length-1))+1;

	for (ll x = 0; x < (1<<(length-2)); x++) {
		check(2*x + add);
		if (solutions == numCoins) break;
	}
}