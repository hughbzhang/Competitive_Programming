/*
ID:bigfish2
LANG:C++
TASK:wormhole
*/


#include <cstdio>
#include <algorithm>
#include <utility>
#include <iostream>
#define A first
#define B second

using namespace std;
typedef pair<int,int> pii;

int path[15];
int par[15];
pii hole[15];
bool vis[15];
int N;
int cnt = 0;
int cur,start;
int num = 0;

void check(){
    //for(int x = 0;x<N;x++) cout << par[x] << " ";
    //cout << endl;
    num++;
    for(start = 0;start<N;start++){
        int lol = 0;
        bool flag = true;
        cur = start;
        while(lol<2*N){
            if(flag) cur = path[cur];
            else cur = par[cur];
            flag = !flag;
            if(cur==-1) break;
            lol++;
        }
        if(cur!=-1){
            cnt++;
            return;
        }
    }
    for(int x = 0;x<N;x++) if(par[x]==path[x]) cout << "LOL";
}

void DFS(int cur){
    if(cur==N){
        check();
        return;
    }
    if(vis[cur]){
        DFS(cur+1);
        return;
    }
    vis[cur] = true;
    for(int x = cur+1;x<N;x++){
        if(vis[x]) continue;
        par[x] = cur;
        par[cur] = x;
        vis[x] = true;
        DFS(cur+1);
        vis[x] = false;
        par[x] = -1;
        par[cur] = -1;
    }
    vis[cur] = false;
}
        
    


int main(){
    freopen("wormhole.in","r",stdin);
    freopen("wormhole.out","w",stdout);
    cin >> N;
    int a,b;
    for(int x = 0;x<N;x++){
        cin >> a >> b;
        hole[x] = pii(b,a);
    }
    sort(hole,hole+N);
    for(int x = 0;x<N-1;x++){
        if(hole[x].A==hole[x+1].A) path[x] = x+1;
        else path[x] = -1;
    }
    path[N-1] = -1;
    for(int x = 0;x<N;x++) par[x] = -1;
    DFS(0);
    cout << cnt << endl;
//    cout << num << endl;
}


