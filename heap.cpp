#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 1e7;
int heap[MAXN+100];
int cnt = 1;

//positive numbers only

bool verify(){
	for(int x = cnt-1;x>=1;x--){
		if(heap[x]<heap[x/2]) return false;
	}
	return true;
}

void print(){
	cout << endl;
	for(int x = 1;x<cnt;x++) cout << heap[x] << " ";
	cout << endl;
}

void swp(int a, int b){
	if(a>=cnt||b>=cnt) return;
	int tmp = heap[a];
	heap[a] = heap[b];
	heap[b] = tmp;
}


void insert(int a){
	int cur = cnt;
	heap[cnt++] = a;
	while(cur>0&&heap[cur]<heap[cur/2]){
		swp(cur,cur/2);
		cur/=2;
	}
	
}

int top(){ return heap[1]; }

void pop(){
	--cnt;
	heap[1] = heap[cnt];
	int cur = 1;
	while(true){
		
		if(2*cur==cnt-1&&heap[cur]>heap[2*cur]){
			swp(cur,2*cur);
			break;
		}
		if(2*cur+1>=cnt) break;
		if(heap[2*cur]<=heap[2*cur+1]&&heap[2*cur]<heap[cur]){
			swp(cur,2*cur);
			cur = 2*cur;
		}
		else if(heap[2*cur+1]<=heap[2*cur]&&heap[2*cur+1]<heap[cur]){
			swp(cur,2*cur+1);
			cur = 2*cur+1;
		}
		else break;
	}
}


void test(){
	srand(7);
	for(int x = 0;x<MAXN;x++){
		int in = rand()%MAXN;
		//cout << in;
		insert(in);
	}
	//cout << endl;
	
	int low = top();
	pop();
	
	//if(!verify()) cout << "B\n";
	
	while(cnt>0){
		//cout << top();
		//if(!verify()) cout << "BA\n";
		if(top()<low) cout << "BAD\n";
		low = top();
		pop();
	}
	cout << endl;
}



int main(){
	test();
	//print();
	




}