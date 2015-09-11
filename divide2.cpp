#include <cstdio>
#include <utility>

using namespace std;

//BUGS NOT FIXED

pair<int,int> divide(int num, int divisor){ // idea is binary search
	if(divisor==0) return INF;


	if(num<0&&divisor<0){
		pair<int,int> pos = divide(-num,-divisor);
		pos.second = -pos.second;
		return pos;	
	}
	if(num<0){
		pair<int,int> pos = divide(-num,divisor);
		pos.first = -pos.first;
		pos.second = -pos.second;
		return pos;
	}
	if(divisor<0){
		pair<int,int> pos = divide(num,-divisor);
		pos.first = -pos.first;
		return pos;
	}



	int low = 0; //lowest possible positive
	int high = num; //highest possible positive

	while(low<high){
		int mid = low + (high-low) >> 1;
		if(num-mid*divisor>=divisor){
			low = mid+1;
		}
		else if(num-mid*divisor<0){
			high = mid-1;
		}
		else{
			low = mid;
			high = mid;
		}
	}
	return make_pair(low,num-low*divisor); //quotient and remainder
}