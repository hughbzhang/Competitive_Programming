#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>

#define MAX 100100

using namespace std;

int N,M,A,B;

vector<int> child[MAX];
bool SC[MAX];
bool LOL[MAX];
int red[MAX];//DFS nums
int green[MAX];//look back nums
bool vis[MAX];
int ssub[MAX];
int lsub[MAX];
bool path[MAX];
int cnt = 0;
int ans = 0;

void DFS(int cur,int par){
    if(vis[cur]) return;
    vis[cur] = true;
    red[cur] = cnt;
    cnt++;
    green[cur] = red[cur];
    path[cur] = true;
    if(SC[cur]) ssub[cur]++;
    if(LOL[cur]) lsub[cur]++;
    for(int x = 0;x<child[cur].size();x++){
        if(child[cur][x]==par) continue;
        if(vis[child[cur][x]]){
            if(path[child[cur][x]]) green[cur] = min(green[cur],green[child[cur][x]]);
        }
        else{
            DFS(child[cur][x],cur);
            green[cur] = min(green[cur],green[child[cur][x]]);
            ssub[cur]+=ssub[child[cur][x]];
            lsub[cur]+=lsub[child[cur][x]];

        }
    }
    path[cur] = false;
    if(green[cur]==red[cur]&&cur>0){
        if((ssub[cur]==0||ssub[cur]==A)||(lsub[cur]==0||lsub[cur]==B)) ans++;
        //cout << cur << " " << par << endl;
    }
}
int main(){
    freopen("cowsplay2.in","r",stdin);
    freopen("cowsplay2.out","w",stdout);
    cin >> N >> M >> A >> B; 
    int a,b;
    for(int x = 0;x<A;x++){
        cin >> a;
        a--;
        SC[a] = true;
    }
    for(int x = 0;x<B;x++){
        cin >> a;
        a--;
        LOL[a] = true;
    }
    for(int x = 0;x<M;x++){
        cin >> a >> b;
        a--;
        b--;
        child[a].push_back(b);
        child[b].push_back(a);
    }
    DFS(0,-1);
    for(int x = 0;x<N;x++){
        //cout << x << " " << lsub[x] << " " << ssub[x] << endl;
    }
    cout << ans << endl;
}




