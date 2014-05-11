#include <cstdio>
#include <iostream>
#include <vector>


using namespace std;

int N,M;

vector<int> adj[50500];
bool vis[50500];
bool mark[50500];
int cnt = 0;
int num = 0;

bool flood(int cur, bool flag){
    if(vis[cur]){
        if(flag==mark[cur]) return true;
        else return false;
    }
    vis[cur] = true;
    mark[cur] = flag;
    num++;
    if(flag) cnt++;
    for(int x = 0;x<adj[cur].size();x++){
        if(!flood(adj[cur][x],!flag)) return false;
    }
    return true;
}


int main(){
    freopen("decorate.in","r",stdin);
    freopen("decorate.out","w",stdout);
    scanf("%d%d",&N,&M);
    for(int x = 0;x<M;x++){
        int a,b;
        scanf("%d%d",&a,&b);
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int best = 0;
    for(int x = 0;x<N;x++){
        if(vis[x]) continue;
        if(!flood(x,0)){
            printf("-1\n");
            return 0;
        }
        best+=max(cnt,num-cnt);
        num = 0;
        cnt = 0;
    }
    
    printf("%d\n",best);


    return 0;
}
