#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int num,size;

bool arr[15][2];
bool vis[15][2];

bool DFS(int y, bool x){
//    cout << y << " " << x << endl;

    if(y<0||y>=size) return 0;
    if(vis[y][x]) return 0;
    vis[y][x] = true;
    if(arr[y][x]) return 0;
    int cnt = 1;
    //if(y==0&&!x) cout << cnt << endl;
    cnt+=DFS(y+1,x);
    cnt+=DFS(y-1,x);
    cnt+=DFS(y,!x);
    if(!x) cnt+=DFS(y-1,!x);
    else cnt+=DFS(y+1,!x);
    //if(y==0&&!x) cout << cnt << endl;
    if(cnt%2==0) return 0;
    else return 1;
}

void reset(){
    for(int x = 0;x<15;x++){
        vis[x][0] = 0;
        vis[x][1] = 0;
    }
}

int main(){
    cin >> num;
    string ANSWER = "";
    for(int x = 0;x<num;x++){
        reset();
        bool ans = false;
        string in;
        cin >> size >> in;
        for(int x = 0;x<size;x++){
            if(in.at(x)=='0') arr[x][0] = false;
            else arr[x][0] = true;
        }
        cin >> in;
        for(int x = 0;x<size;x++){
            if(in.at(x)=='0') arr[x][1] = false;
            else arr[x][1] = true;
        }
        for(int x = 0;x<size;x++){
            if(DFS(x,0)||DFS(x,1)){
                ans = true;
                break;
            }
        }
        if(ans) cout << "NO" << endl;
        else cout << "YES" << endl;
        //if(ans) ANSWER+= "NO\n";

        //else ANSWER+= "YES\n";
    }
//    cout << ANSWER;


}
