#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int next_server_number(vector<int> arr){
	sort(arr.begin(),arr.end());
	for(int x = 0;x<arr.size();x++){
		if(arr[x]!=x+1) return x+1;
	}
	return arr.size()+1;
}

void test(){

	int tests[5][5] = {{5,3,1,-1,-1},{5,4,1,2,-1},{3,2,1,-1,-1},{2,3,-1,-1,-1},{-1,-1,-1,-1,-1}};
	int length[] = {3,4,3,2,0};
	vector<int> arr;
	for(int y = 0;y<5;y++){
		for(int x = 0;x<length[y];x++){
			arr.push_back(tests[y][x]);
		}
		cout << next_server_number(arr) << endl;
		arr.clear();
	}
	/*arr.push_back(5);
	arr.push_back(3);
	arr.push_back(1);
	cout << next_server_number(arr) << endl;
	arr.clear();
	arr.push_back(5);
	arr.push_back(4);
	arr.push_back(1);
	arr.push_back(2);
	cout << next_server_number(arr) << endl;
	arr.clear();
	arr.push_back(3);
	arr.push_back(2);
	arr.push_back(1);
	cout << next_server_number(arr) << endl;
	arr.clear();
	arr.push_back(2);
	arr.push_back(3);
	cout << next_server_number(arr) << endl;
	arr.clear();
	cout << next_server_number(arr) << endl;
	arr.clear();*/	
}


int main(){

	test();
	

/*	  >> next_server_number([5, 3, 1])
  2
  >> next_server_number([5, 4, 1, 2])
  3
  >> next_server_number([3, 2, 1])
  4
  >> next_server_number([2, 3])
  1
  >> next_server_number([])
  1
  */


	//cout << next_server_number(arr) << endl;





}