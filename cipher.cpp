#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string message;
int length, cycles;
string decrypt;
const int MAXL = 24;

int oneBit[MAXL];



/*void print(){
	for(int x = length-1;x>=0;x--){
		if(decrypt&(1<<x)) cout << 1;
		else cout << 0;
	}
	cout << endl;
}

int convert(string in){
	int ret = 0;
	for(int x = 0;x<in.length();x++){
		if(in[in.length()-1-x]=='1') ret += (1<<x);
	}
	return ret;
}

void setup(){
	oneBit[0] = 1;
	for(int x = 1;x<MAXL;x++) oneBit[x] = (oneBit[x-1] << 1);
}*/

int main(){
	cin >> length >> cycles >> message;
	decrypt = message[0];
	//print();
	bool curDigit = (decrypt[0] == '1');
	for(int x = 1;x<length;x++){
		//if(decrypt[x-1]=='1') curDigit = !curDigit;
		if(x-cycles>=0&&decrypt[x-cycles]=='1') curDigit = !curDigit;
		bool nextDigit = (message[x]=='1');


		if(curDigit!=nextDigit){
			decrypt+='1';
			curDigit = !curDigit;
		}
		else decrypt+='0'; 
		//print();
	}
	cout << decrypt << endl;
	


}