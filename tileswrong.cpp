#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int N,M;
bool grid[2020][2020];
bool vis[2020][2020];
char ans[2020][2020];

int Sx,Sy;
string in;
int cnt = 0;


bool ok(int y, int x){
    if(y<0||y>=N||x<0||x>=M) return false;
    return grid[y][x];


bool DFS(int y, int x, int dir){
    //0 means came from up
    //1 means came from left
    //2 means came from down
    //3 means came from right
    if(y<0||y>=N||x<0||x>=M) return true;
    if(!grid[y][x]) return true;
    if(vis[y][x]) return false;//there is a cycle

    //cout << y << " " << x << endl;
    vis[y][x] = true;
    cnt++;
    if(dir!=0&&!DFS(y-1,x,2)) return false;
    if(dir!=1&&!DFS(y,x-1,3)) return false;
    if(dir!=2&&!DFS(y+1,x,0)) return false;
    if(dir!=3&&!DFS(y,x+1,1)) return false;
    return true;
}

void fill(int y, int x, int dir){
    while(true){
        if(dir!=0&&ok(y-1,x)){
            y--;
            dir = 2;
            continue;
        }
        if(dir!=1&&ok(y,x-1)){
            x--;
            dir = 3;
            continue;
        }
        if(dir!=2&&ok(y+1,x)){
            y++;
            dir = 0;
            continue;
        }
        if(dir!=3&&ok(y,x+1)){
            y++;
            dir = 1;
            continue;
        }
        break;
    }
    while(true){
        if(grid[y+1][x]){
            ans[y][x] = '^';
            ans[y+1][x] = 'v';
            if(ok(y+2,x)) y +=2;
        


int main(){
    cin >> N >> M;
    for(int y = 0;y<N;y++){
        cin >> in;
        for(int x = 0;x<M;x++){
            if(in.at(x)=='.'){
                grid[y][x] = true;
            }
        }
    }
    for(int y = 0;y<N;y++){
        for(int x = 0;x<M;x++){
            if(!DFS(y,x,-1)||(cnt%2)==1){
                cout << "Not unique\n";
                return 0;
            }
            fill(y,x);
            cnt = 0;
        }
    }
}

