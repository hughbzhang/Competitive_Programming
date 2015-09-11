#include <cstdio>
#include <iostream>

using namespace std;

int add(int one, int two);
int subtract(int one, int two);
int neg(int in){ return (~in)+1; }


int add(int one, int two){ //add two positive integers
	if(one<0) return subtract(two,neg(one));
	if(two<0) return subtract(one,neg(two));

	while(two!=0){
		int nocarry = one^two;
		int carry = (one&two) << 1;
		one = nocarry;
		two = carry;
	}
	return one;
}

int subtract(int one, int two){ // one-two one>two
	if(one<two) return neg(subtract(two,one));
	if(two<0) return add(one,neg(two));
	while(two!=0){
		int nocarry = one^two;
		int carry = ((~one)&two) << 1;
		one = nocarry;
		two = carry;
	}
	return one;
}

const int MAXN = 2*1e6;
const int mil = 1e6;


void input(){
	while(true){
		int a,b;
		cin >> a >> b;
		cout << add(a,b) << endl;
	}
}

int main(){
	srand(9);


	for(int x = 0;x<MAXN;x++){
		int a = rand()%MAXN-mil;
		int b = rand()%MAXN-mil;
		int lol = rand()%2;
		if(lol){
			if(add(a,b)!=a+b) cout << "ADD " << a << " " << b << "\n";
		}
		else{
			if(subtract(a,b)!=a-b) cout << "SUB " << a << " " << b << "\n";
		}
		
	}




}