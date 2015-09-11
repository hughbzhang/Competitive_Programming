#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Tracker {


	map<string,vector<int> > data;


	int next_server_number(vector<int> arr){
		sort(arr.begin(),arr.end());
		for(int x = 0;x<arr.size();x++){
			if(arr[x]!=x+1) return x+1;
		}
		return arr.size()+1;
	}
public:
	string allocate(string name){
		int num = next_server_number(data[name]);
		data[name].push_back(num);

		return name + to_string(num);
	}

	void deallocate(string name){
		int place = 1;
		int num = 0;
		for(int x = name.length()-1;x>=0;x--){
			if(name[x]>='0'&&name[x]<='9'){
				num+=place*(name[x]-'0');
				place*=10;
			}
			else{
				name = name.substr(0,x+1);
				break;
			}
		}
		cout << num << " " << name << endl;
		sort(data[name].begin(),data[name].end());
		bool rem = false;
		for(int x = 0;x<data[name].size();x++){
			if(data[name][x]==num){
				rem = true;
			}
			if(rem&&x!=data[name].size()-1){
				data[name][x] = data[name][x+1];
			}
		}
	}
	Tracker(){

	}

	
};


int main(){
	Tracker tracker = Tracker();
	cout << tracker.allocate("apibox") << endl;
	cout << tracker.allocate("apibox") << endl;
	tracker.deallocate("apibox1");
	cout << tracker.allocate("apibox") << endl;
	cout << tracker.allocate("testbox") << endl;




}
