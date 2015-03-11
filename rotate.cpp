#include <cstdio>
#include <iostream>
#define MAX 10

using namespace std;

int mat[MAX][MAX];

void print(){
    for(int y = 0;y<MAX;y++){
        for(int x = 0;x<MAX;x++){
            cout << mat[y][x] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


void rot(){
    for(int y = 0;y<MAX/2;y++){
        for(int x = y;x<MAX-y-1;x++){
            int temp = mat[y][x];
            mat[y][x] = mat[MAX-x-1][y];
            mat[MAX-x-1][y] = mat[MAX-y-1][MAX-x-1];
            mat[MAX-y-1][MAX-x-1] = mat[x][MAX-y-1];
            mat[x][MAX-y-1] = temp;

        }        
    }
}

int main(){

    for(int x = 0;x<100;x++){
        mat[x/MAX][x%MAX] = x;
    }
    print();


    rot();
    print();
}
    

