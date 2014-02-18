#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <queue>
#include <utility>
#include <vector>

#define A first
#define B second
#define LARGE (1e8)

using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
int matrix[80][80];
priority_queue<piii,vector<piii>, greater<piii> > q;

int dist[80][80];
bool vis[80][80];

int main(){
    ifstream fin ("matrix.txt");
    int Y = 0;
    while(fin){
        string s;
        fin >> s;
        stringstream read (s);
        int num;
        int X = 0;
        while(read >> num){
            if(read.peek()==',') read.ignore();
            matrix[Y][X] = num;
            X++;
        }
        Y++;
    }
    for(int y = 0;y<80;y++) for(int x = 0;x<80;x++) dist[y][x] = LARGE;
    for(int y = 0;y<80;y++){
        q.push(piii(matrix[y][0],pii(y,0)));
    }
    
    while(!q.empty()){
        piii cur = q.top();
        q.pop();
        int cost = cur.A;
        int y = cur.B.A;
        int x = cur.B.B;
        if(x<0||x>=80||y<0||y>=80) continue;
        if(vis[y][x]) continue;
        vis[y][x] = true;
        if(dist[y][x]> cost) dist[y][x] = cost;
        if(x==79){
            cout << dist[y][x] << endl;
            break;
        }
        q.push(piii(cost+matrix[y+1][x],pii(y+1,x)));
        q.push(piii(cost+matrix[y-1][x],pii(y-1,x)));
        q.push(piii(cost+matrix[y][x+1],pii(y,x+1)));
        //q.push(piii(cost+matrix[y][x-1],pii(y,x-1)));
    }

    return 0;    
}
