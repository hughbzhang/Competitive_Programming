#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

void swp(int* arr, int one, int two){
	int tmp = arr[one];
	arr[one] = arr[two];
	arr[two] = tmp;
}

void qsrt(int* arr, int left, int right){
	if(left>=right) return;
	int pivot = arr[left];
	int l = left;
	int r = right;
	while(l<r){
		while(l<r&&arr[l]<pivot) l++;
		while(l<r&&arr[r]>pivot) r--;
		swp(arr,l,r);
	}
	if(l!=r) cout << "wrong\n";
	qsrt(arr,left,l);
	qsrt(arr,r+1,right);
	return;
}



const int MAXN = 1e6;
int toSort[MAXN];

void setup(){
	for(int x = 0;x<MAXN;x++) toSort[x] = x;
	random_shuffle(toSort,toSort+MAXN);
}

bool check(int* arr){
	for(int x = 0;x<MAXN;x++){
		if(arr[x]!=x) return false;
	}
	return true;
}

int main(){
	srand(7);
	setup();
	qsrt(toSort,0,MAXN-1);
	
	cout << check(toSort) << endl;




}