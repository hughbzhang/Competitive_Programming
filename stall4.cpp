/*
ID: bigfish2
LANG:C++
TASK:stall4
*/
#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#define A first
#define B second
#define LARGE 100000

using namespace std;
typedef pair<int,int> pii;
bool adj[1000][1000];
int total[1000];
int ans = 0;
bool vis[1000];
int par[1000];
priority_queue<pii> q;
int temp, N, M, a;

void reset(){
    while(!q.empty()) q.pop();
    for(int x = 0;x<1000;x++){
        total[x] = 0;
        vis[x] = false;
        par[x] = -1;
    }
}

void dijk(){
    reset();
    total[0] = LARGE;
    q.push(pii(LARGE,0));
    while(!q.empty()){
        int cur = q.top().B;
        q.pop();

        if(cur==N+M+1) return;
        if(total[cur]==0) return;
        if(vis[cur]) continue;
//        cout << cur << endl;
        vis[cur] = true;
        for(int x = 0;x<=N+M+1;x++){
            if(total[x]==0&&adj[cur][x]){
                total[x] = 1;
                par[x] = cur;
                q.push(pii(total[x],x));
            }
        }
    }
}
void flow(){
    do{
        dijk();
        ans++;
        int cur = N+M+1;
        while(cur!=0){
            if(par[cur]==-1) break;
            adj[par[cur]][cur] = false;
            adj[cur][par[cur]] = true;
            cur = par[cur];
        }
    } while(total[N+M+1]!=0);
    ans--;
}
        
int main(){
    freopen("stall4.in","r",stdin);
    freopen("stall4.out","w",stdout);
    cin >> N >> M;
    for(int x = 1;x<=N;x++){
        cin >> a;
        for(int b = 0;b<a;b++){
            cin >> temp;
            adj[x][N+temp] = true;
        }
        adj[0][x] = true;
    }
    for(int x = N+1;x<=N+M;x++){
        adj[x][N+M+1] = true;
    }
    flow();
    /*for(int y = 0;y<12;y++){
        for(int x = 0;x<12;x++){
            if(adj[y][x]) cout << 1;
            else cout << 0;
        }
        cout << endl;
    }*/
    cout << ans << endl;
}


