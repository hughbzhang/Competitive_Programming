#include <iostream>
#include <cstdio>

using namespace std;

int** mat;


void printSpiralMatrix(int** matrix, int rows, int cols){
//prints the matrix in spiral order in linear time to the number of elements (quadratic to rows/cols)
	
	//setup arrays and stuff

	bool didVisit[rows][cols];
	for(int y = 0;y<rows;y++){
		for(int x = 0;x<cols;x++){
			didVisit[y][x] = false;
		}
	}
	//order is right, down, left, up
	int xDir[4] = {1,0,-1,0};//right = 1, left = -1
	int yDir[4] = {0,1,0,-1};//down = 1, up = -1
	
	int curDir = 0;//start facing right
	
	int curX = 0;//start at origin
	int curY = 0;
	
	for(int cnt = 0;cnt<rows*cols;++cnt){
		cout << matrix[curY][curX] << " ";
		didVisit[curY][curX] = true;
		int nextY = curY+yDir[curDir];
		int nextX = curX+xDir[curDir];
		if(nextY<0||nextX<0||nextY>=rows||nextX>=cols||didVisit[nextY][nextX]){
		//if you are out of bounds or visited before swap direction
			curDir++;
			curDir%=4;
		}
		curX = curX+xDir[curDir]; //update X and Y
		curY = curY+yDir[curDir];
	}
	cout << endl;
}



int main(){
	//testing after submitted code
	freopen("maze.txt","r",stdin);
	int row,col;
	cin >> row >> col;
	mat = new int*[row];
	for(int y = 0;y<row;y++){
		mat[y] = new int[col];
		for(int x = 0;x<col;x++){
			cin >> mat[y][x];
		}
	}
	printSpiralMatrix(mat,row,col);

}





