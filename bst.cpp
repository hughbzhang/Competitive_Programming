#include <cstdio>
#include <iostream>


using namespace std;

class node{
public: // can also make these variables private
	int value;
	node* leftChild;
	node* rightChild;
	node* parent;
	node(int value){
		this->value = value;
		leftChild = NULL;
		rightChild = NULL;
		parent = NULL;
	}
};

node* root;

node* nextLargest(node* cur){
	if(cur->rightChild!=NULL){
		cur = cur->rightChild;
		while(cur->leftChild!=NULL) cur = cur->leftChild;
		return cur;
	}
	else{
		node* par = cur->parent;
		while(par->value<cur->value){
			par = par->parent;
			cur = cur->parent;
		}
		if(par->value>cur->value) return par;
		else return NULL; //no value larger
	}
}



node* nextNode(node* cur, int target){ //false is move left, true is move right. CHECK IF SAME EARLIER
	if((cur->value)>target) return cur->leftChild;
	else return cur->rightChild;
}

node* find(int target){
	node* cur = root;
	while(cur!=NULL){
		if(cur->value==target) return cur;
		else cur = nextNode(cur,target);
	}
	return NULL;
}

bool exists(int target){
	node* cur = root;
	while(cur!=NULL){
		if(cur->value==target) return true;
		else cur = nextNode(cur,target);
	}
	return false;
}

bool insert(int target){
	if(root==NULL){
		root = new node(target);
		root->parent = root;
		return true;
	}

	if(target==root->value) return false;
	node* par = root;
	node* cur = nextNode(par,target);
	
	while(cur!=NULL){
		if(cur->value==target) return false;
		else{
			par = nextNode(par,target);
			cur = nextNode(cur,target);
		}
	}

	cur = new node(target);
	if(par->value<target) par->rightChild = cur;
	else par->leftChild = cur;
	cur->parent = par;

	return true;
}

node* findMin(){
	node* cur = root;
	while(cur->leftChild!=NULL) cur = cur->leftChild;
	return cur;
}

bool remove(int target){
	node* cur = find(target);
	if(cur==NULL) return false; // not here

	node* par = cur->parent;
	bool dir = false; // false is left
	if(par->value<cur->value) dir = true;


	if(cur->leftChild!=NULL||cur->rightChild!=NULL){ // if not a leaf
		node* sub;


		if(cur->leftChild==NULL) sub = cur->rightChild;
		else if(cur->rightChild==NULL) sub = cur->leftChild;
		else{

			sub = nextLargest(cur);
			node* subPar = sub->parent;

			node* replacement = sub->rightChild;

			if(subPar->value<sub->value) subPar->rightChild = replacement;
			else subPar->leftChild = replacement;
			if(replacement!=NULL) replacement->parent = subPar;
		//if(target==1) cout <<"L\n";
			if(cur->leftChild!=NULL){
				sub->leftChild = cur->leftChild;
				cur->leftChild->parent = sub;
			}
			if(cur->rightChild!=NULL){
				sub->rightChild = cur->rightChild;
				cur->rightChild->parent = sub;
			}
			
		}

		if(cur==root){
			root = sub;
			sub->parent = sub;
		}
		else{
			sub->parent = par;
			if(dir) par->rightChild = sub;
			else par->leftChild = sub;
		}		
	}
	
	else{
		if(cur==root) root = NULL;
		else if(dir) par->rightChild = NULL;
		else par->leftChild = NULL;
	}
	
	delete cur;
	return true;

}

const int mil = 1000000;
bool use[mil];
int arr[mil];

void test(int N){


	srand(7);
	
	for(int x = 0;x<10*N;x++){
		int a = rand()%mil;
		//if(x==N-1) cout << a << endl;
		if(use[a]) remove(a);
		else insert(a);
		
		use[a] = !use[a];

	}
	int idx = 0;
	for(int x = 0;x<mil;x++){
		if(use[x]){
			arr[idx++] = x;
			//cout << x << " ";
		}
	}
	//cout << endl;


	node* start = findMin();
	int cnt = 0;
	while(start!=NULL){
		//cout << start->value << " ";
		if(start->value!=arr[cnt++]) cout << "BAD\n";
		start = nextLargest(start);
	}
	//cout << endl;
	//if(cnt!=idx) cout << "W\n";

}




int main(){
	int N;
	//cin >> N;
	test(mil);
	//remove(1);
	/*node* lol = root->leftChild;
	
	cout << lol->value << endl;
	cout << lol->leftChild << endl;
	//cout << root->leftChild->rightChild->value << endl;
	cout << lol->rightChild->value << endl;*/
	
	
}



/*else if(cur->leftChild!=NULL){
		if(dir){
			par->rightChild = cur->leftChild;
			(cur->leftChild)->parent = par;
		}
		else{
			par->leftChild = cur->leftChild;
			(cur->leftChild)->parent = par;
		}
		if(cur==root){
			root = cur->leftChild;
			(cur->leftChild)->parent = cur->leftChild;
		}
	}
	else if(cur->rightChild!=NULL){
		if(dir){
			par->rightChild = cur->rightChild;
			(cur->rightChild)->parent = par;
		}
		else{
			par->leftChild = cur->rightChild;
			(cur->rightChild)->parent = par;
		}
		if(cur==root){
			root = cur->rightChild;
			(cur->rightChild)->parent = cur->rightChild;
		}
	}*/