#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

typedef pair<int,int> pp;

int N, M;
string grid[25];
string words[25];

pp check(int i)
{
	pp ret = pp(-2,-2);
	int length = words[i].length();
	for(int r=0;r<N;r++) for(int c=0;c<N;c++){
			if(c+length-1<N){
				int j;
				for(j=0;j<words[i].length();j++){
					if(grid[r][c+j] != words[i][j]) break;
				}
				if(j == words[i].length()){
					ret = pp(r,c);
				}
			}

			if(r+length-1<N){
				int j;
				for(j=0;j<words[i].length();j++){
					if(grid[r+j][c] != words[i][j]) break;
				}
				if(j == words[i].length()){
					ret = pp(r,c);
				}
			}

			if(r-length+1>=0){
				int j;
				for(j=0;j<words[i].length();j++){
					if(grid[r-j][c] != words[i][j]) break;
				}
				if(j == words[i].length()){
					ret = pp(r,c);
				}
			}

			if(c-length+1>=0){
				int j;
				for(j=0;j<words[i].length();j++){
					if(grid[r][c-j] != words[i][j]) break;
				}
				if(j == words[i].length()){
					ret = pp(r,c);
				}
			}

			if(r+length-1<N && c+length-1<N){
				int j;
				for(j=0;j<words[i].length();j++){
					if(grid[r+j][c+j] != words[i][j]) break;
				}
				if(j == words[i].length()){
					ret = pp(r,c);
				}
			}

			if(r+length-1<N && c-length+1>=0){
				int j;
				for(j=0;j<words[i].length();j++){
					if(grid[r+j][c-j] != words[i][j]) break;
				}
				if(j == words[i].length()){
					ret = pp(r,c);
				}
			}

			if(r-length+1>=0 && c+length-1<N){
				int j;
				for(j=0;j<words[i].length();j++){
					if(grid[r-j][c+j] != words[i][j]) break;
				}
				if(j == words[i].length()){
					ret = pp(r,c);
				}
			}

			if(r-length+1>=0 && c-length+1>=0){
				int j;
				for(j=0;j<words[i].length();j++){
					if(grid[r-j][c-j] != words[i][j]) break;
				}
				if(j == words[i].length()){
					ret = pp(r,c);
				}
			}


		}
	return ret;
	//	if(!found) cout<<"-1 -1"<<endl;
}

int main()
{
	cin>>N>>M;
	for(int i=0;i<M;i++) cin>>words[i];
	for(int i=0;i<N;i++) cin>>grid[i];
	for(int i=0;i<M;i++){
		pp ans = check(i);
		cout<<ans.first+1<<" "<<ans.second+1<<endl;
	}
}