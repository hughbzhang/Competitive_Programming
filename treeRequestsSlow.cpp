#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


const int MAXN = 500500;

int maxDepth = 0;
int nodes, queries;
int par[MAXN];
int depth[MAXN];
char letter[MAXN];
vector<int> child[MAXN];

vector<string> dp[MAXN];
//dp[N][k] is at node N and depth[N]+k
//this vector holds all precomputed queries
//an empty string or one char means you can have a palindrome
//more than one char means these characters must be counterbalanced


//we are one indexing here

int DFS(int curNode, int curDepth){
	//cout << curNode << " " << curDepth << endl;
	if(curDepth>maxDepth) maxDepth = curDepth;
	depth[curNode] = curDepth;
	int deepest = 0; // deepest holds greatest depth of any children from you (including you)
	for(int x = 0;x<child[curNode].size();x++){
		int nextDeep = DFS(child[curNode][x],curDepth+1);
		deepest = max(deepest,nextDeep);
	}
	deepest++; //add yourself
	string first(1,letter[curNode]);
	dp[curNode].push_back(first); //dp[curNode][0]

	for(int x = 1;x<deepest;x++){
		string next = "";
		for(int a = 0;a<child[curNode].size();a++){
			if(dp[child[curNode][a]].size()>=x) next+=dp[child[curNode][a]][x-1];
		}
		sort(next.begin(),next.end());
		string add = "";
		if(next.length()>0){
			add+=next[0];
			for(int a = 1;a<next.length();a++){
				if(next[a]==add[add.length()-1]) add.erase(add.length()-1,1);//erase last character if same
				else add+=next[a];
			}
		}
		dp[curNode].push_back(add);
	}
	return deepest;
}

void output(){
	for(int x = 0;x<queries;x++){
		int vertex,vdepth;
		cin >> vertex >> vdepth;
		//cout << "YES\n";
		//continue;
		if(vdepth<depth[vertex]||vdepth>maxDepth) cout << "Yes\n"; //empty palindrome
		else if(dp[vertex][vdepth-depth[vertex]].length()<2) cout << "Yes\n"; //can form palindrome
		else cout << "No\n";
	}
}

void print(){
	for(int x = 1;x<=nodes;x++){
		for(int a = 0;a<dp[x].size();a++){
			cout << dp[x][a] << " ";
		}
		cout << endl;
	}
}


int main(){
	//freopen("in.txt","r",stdin);
	ios::sync_with_stdio(0);
	cin >> nodes >> queries;
	for(int x = 2;x<=nodes;x++){
		int a;
		cin >> a;
		par[x] = a;
		child[a].push_back(x);
	}
	string in;
	cin >> in;
	for(int x = 1;x<=nodes;x++) letter[x] = in[x-1];

	DFS(1,1);
	
	output();

}