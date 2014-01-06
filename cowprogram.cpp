#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

int num;

//-1 is cycle
//
ll arr[200001];
ll dist[200001][2];//0 is left 1 is right
bool vis[200001][2];

ll search(int cur,int dir){
    if(cur<0||cur>num) return 0;
    if(vis[cur][dir]) return dist[cur][dir];
    vis[cur][dir] = true;
    if(dir){
        ll next = search(cur+arr[cur],0);
        if(next!=-1) return dist[cur][dir] = arr[cur]+next;
        else return dist[cur][dir] = -1;
    }
    else{
        ll next = search(cur-arr[cur],1);
        if(next!=-1) return dist[cur][dir] = arr[cur]+next;
        else return dist[cur][dir] = -1;
    }
}

int main(){
    
    cin >> num;
    arr[0] = -1;
    vis[0][0] = true;
    vis[0][1] = true;
    for(int x = 0;x<num;x++){
        dist[x][0] = -1;
        dist[x][1] = -1;
    }
    
    for(int x = 1;x<num;x++){
        cin >> arr[x];
    }
    for(int x = 1;x<num;x++){
        search(x,0);
        search(x,1);
    }
    for(int x = 1;x<num;x++){
        ll ans = dist[x][0];
        if(ans!=-1) cout << ans+x << "\n";
        else cout << "-1\n";
    }



}
