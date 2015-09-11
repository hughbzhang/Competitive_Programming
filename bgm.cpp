#include <cstdio>
#include <string>
#include <map>
#include <iostream>
#include <cmath>

using namespace std;

string key = "BESIGOM";
string words[3] = {"BESSIE","GOES","MOO"};

map<char,int*> alphabet;
map<char,int> indexOf;
int num;
int curLayout[7];
long long ans = 0;


void setup(){
	for(int x = 0;x<key.length();x++){
		alphabet[key[x]] = new int[7];
		for(int a = 0;a<7;a++) alphabet[key[x]][a] = 0;
		indexOf[key[x]] = x;
	}
	
}

bool pass(){
	for(int a = 0;a<3;a++){
		int sum = 0;
		for(int x = 0;x<words[a].length();x++){
			sum+=curLayout[indexOf[words[a][x]]];
		}	
		if(sum%7==0) return true;
	}
	return false;
}

int main(){

	freopen("bgm.in","r",stdin);
	freopen("bgm.out","w",stdout);

	setup();
	cin >> num;
	for(int x = 0;x<num;x++){
		char c;
		int in;
		cin >> c >> in;
		in %=7;
		if(in<0) in += 7; // if less than 0
		alphabet[c][in]++;
	}
	int all = pow(7,7);//0 to 7^7-1 is all the possible values for everything
	for(int x = 0;x<all;x++){
		int curAssign = x;
		for(int a = 0;a<7;a++){
			curLayout[a] = curAssign%7;
			curAssign/=7;
		}
		if(pass()){
			long long add = 1;
			for(int a = 0; a<7;a++)
				add*=alphabet[key[a]][curLayout[a]];
			
			ans += add;
		}

	}

	cout << ans << endl;
	



}