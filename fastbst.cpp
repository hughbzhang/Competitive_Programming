#include <cstdio>
#include <iostream>

using namespace std;

class node{
public:
	int val;
	node* left;
	node* right;
	node* parent;
	node(int in){
		val = in;
		left = NULL;
		right = NULL;
		parent = NULL;
	}
};

node* root = NULL;
const int MAXN = 1e6;
bool arr[MAXN];
int num[MAXN];


bool exists(int val){
	node* cur = root;
	while(cur!=NULL){
		if(cur->val==val) return true;
		if(cur->val>val) cur = cur->left;
		else cur = cur->right;
	}
	return false;
}

node* find(int val){
	node* cur = root;
	while(cur!=NULL){
		if(cur->val==val) return cur;
		if(cur->val>val) cur = cur->left;
		else cur = cur->right;
	}
	return NULL;
}

node* findPar(int val){ // finds parent of node not yet in tree
	if(exists(val)||root==NULL) return NULL;
	
	node* cur = root;
	while(cur!=NULL){ // condition doesn't matter
		if(cur->val>val){
			if(cur->left!=NULL) cur = cur->left;
			else return cur;
		}
		else{
			if(cur->right!=NULL) cur = cur->right;
			else return cur;
		}
	}
	//should never reach here
	return NULL;
}

bool insert(int val){
	if(root==NULL){
		root = new node(val);
		root->parent = root;
		return true;
	}

	if(exists(val)) return false; //already inside
	node* par = findPar(val);
	//cout << par->val << endl;
	node* next = new node(val);
	next->parent = par;
	if(val>par->val) par->right = next;
	else par->left = next;

	//cout << root->val << endl;
	//cout << root->left->val << endl;

	return true;
}

node* successor(node* cur){
	node* original = cur;
	if(cur->right!=NULL){
		cur = cur->right;
		while(cur->left!=NULL) cur = cur->left;
		return cur;
	}
	else{
		while(cur!=root&&cur->parent->val<cur->val) cur = cur->parent;
		cur = cur->parent;
		if(cur->val<=original->val) return NULL; //root thats not part of it.
		else return cur;
	}
}

node* findMin(){
	node* cur = root;
	while(cur->left!=NULL) cur = cur->left;
	return cur;
}

bool remove(int num){
	if(!exists(num)) return false;
	node* curNode = find(num);
	if(curNode->left==NULL&&curNode->right==NULL){
		if(curNode==root) root = NULL;
		else{
			node* par = curNode->parent;
			if(par->val>num) par->left = NULL;
			else par->right = NULL;
		}
		delete curNode;
	}
	else if(curNode->left!=NULL&&curNode->right!=NULL){
		node* swap = successor(curNode);
		if(swap==NULL) cout << "LOL\n";
		int swpval = swap->val;
		remove(swap->val);
		curNode->val = swpval;
	}
	else{// one child
		node* replace;
		if(curNode->left!=NULL) replace = curNode->left;
		else replace = curNode->right;

		curNode->val = replace->val;
		curNode->right = replace->right;
		curNode->left = replace->left;
		if(curNode->left!=NULL) curNode->left->parent = curNode;
		if(curNode->right!=NULL) curNode->right->parent = curNode;
		delete replace;
	}



	
	return true;
}

void test(int N){
	srand(20);
	int cnt = 0;
	for(int x = 0;x<N*10;x++){
		int a = rand()%MAXN;
		if(arr[a]) remove(a);
		else insert(a);
		arr[a] = !arr[a];
	}
	for(int x = 0;x<MAXN;x++){
		if(arr[x]){
			num[cnt++] = x;
			//cout << x << " ";
		}
	}
	//cout << endl;
	node* cur = findMin();
	int pnt = 0;
	while(cur!=NULL){
		//cout << cur->val << " ";
		if(num[pnt]!=cur->val) cout << "BAD\n";
		pnt++;
		cur = successor(cur);
	}
	//cout << endl;
}


int main(){
	test(MAXN);

	
}




