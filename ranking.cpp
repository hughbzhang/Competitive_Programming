#include <cstdio>
#include <vector>

using namespace std;
typedef vector<int>::iterator vi;

vector<int> child[1010];
bool par[1010];
bool vis[1010];
bool reach[1010][1010];
int num,pairs;
long long ans = 0;

void DFS(int start, int cur){
    reach[start][cur] = true;
    vis[cur] = true;
    for(vi it = child[cur].begin();it!=child[cur].end();++it){
        if(!vis[*it]) DFS(start,*it);
    }
}

int main(){
    freopen("ranking.in","r",stdin);
    freopen("ranking.out","w",stdout);
    scanf("%d%d",&num,&pairs);
    for(int x = 0;x<pairs;x++){
        int a,b;
        scanf("%d%d",&a,&b);
        a--;
        b--;
        reach[a][b] = true;
        par[b] = true;
        child[a].push_back(b);
    }
    for(int x = 0;x<num;x++){
        for(int y = 0;y<num;y++) vis[y] = false;
        DFS(x,x);
    }
    for(int x = 0;x<num;x++){
        for(int y = 0;y<num;y++){
            if(!reach[y][x]&&!reach[x][y]) ans++;
        }
    }
    printf("%lld\n",ans/2);

}
