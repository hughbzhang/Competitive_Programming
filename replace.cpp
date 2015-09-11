#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int length, queries;
string origin;
int val = 0;

void calc(){
	int cnt = 0;
	for(int x = 0;x<length;x++){
		if(origin[x]=='.') cnt++;
		else{
			cnt--;
			if(cnt>0) val+=cnt;
			cnt = 0;
		}
	}
	cnt--;
	if(cnt>0) val+=cnt;
}

int main(){

	//freopen("in.txt","r",stdin);

	cin >> length >> queries;
	cin >> origin;
	calc();
	for(int x = 0;x<queries;x++){
		int index;
		char next;
		cin >> index >> next;
		index--;
		if(origin[index]=='.'||next=='.'){//if no periods involved, nothing matters
			if(origin[index]==next);//if both periods or both anything, nothing matters
			else if(origin[index]=='.'){
				int sub = 2;
				if(index<0||origin[index-1]!='.') sub--;
				if(index>length-2||origin[index+1]!='.') sub--;
				val-=sub;
			}
			else if(next=='.'){
				int add = 2;
				if(index<0||origin[index-1]!='.') add--;
				if(index>length-2||origin[index+1]!='.') add--;
				val+=add;
			}
			else{
				//something went wrong

			}
		}
		origin[index] = next;
		cout << val << endl;
		
	}
}