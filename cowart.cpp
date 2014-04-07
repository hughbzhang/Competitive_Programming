#include <cstdio>
#include <string>
#include <iostream>

using namespace std;


//0 = red
//1 = green
//2 = blue

int field[101][101];
bool vis[101][101];
int num;


bool equal(int y, int x, int nexty, int nextx,bool flag){
    if(flag) return field[y][x]==field[nexty][nextx];
    else{
        if(field[y][x]==2) return field[nexty][nextx] == 2;
        else return field[nexty][nextx]!=2;
    }

}

void search(int y, int x, bool flag){
    //false means cow
    //true means human
    if(y<0||x<0||y>=num||x>=num) return;
    if(vis[y][x]) return;
    vis[y][x] = true;
    if(equal(y,x,y-1,x,flag)) search(y-1,x,flag);
    if(equal(y,x,y+1,x,flag)) search(y+1,x,flag);
    if(equal(y,x,y,x-1,flag)) search(y,x-1,flag);
    if(equal(y,x,y,x+1,flag)) search(y,x+1,flag);
}


int main(){
    ios::sync_with_stdio(0);
    freopen("cowart.in","r",stdin);
    freopen("cowart.out","w",stdout);
    cin >> num;
    string in;
    for(int x = 0;x<num;x++){
        cin >> in;
        for(int a = 0;a<num;a++){
            if(in.at(a)=='R') field[x][a] = 0;
            else if(in.at(a)=='G') field[x][a] = 1;
            else field[x][a] = 2;
        }
    }
    int cow = 0;
    int human = 0;
    for(int y = 0;y<num;y++){
        for(int x = 0;x<num;x++){
            if(!vis[y][x]){
                search(y,x,0);
                cow++;
            }
        }
    }
    for(int y = 0;y<num;y++) for(int x = 0;x<num;x++) vis[y][x] = 0;

    for(int y = 0;y<num;y++){
        for(int x = 0;x<num;x++){
            if(!vis[y][x]){
                search(y,x,1);
                human++;
            }
        }
    }
    cout << human << " " << cow << endl;
    return 0;
}
