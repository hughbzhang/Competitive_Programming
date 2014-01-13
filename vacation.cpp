#include <cstdio>
#include <vector>

#define MAX 50500

using namespace std;
typedef vector<int>::iterator vi;

int dp[MAX][2];
vector<int> child[MAX];
vector<int> adj[MAX];
int par[MAX];
// 0 means no cow at that station
// 1 means there is


int num;

void init(){
    for(int x = 0;x<MAX;x++){
        par[x] = -1;
    }
}


void rec(int cur){
    if(child[cur].empty()){
        dp[cur][1] = 1;
        dp[cur][0] = 0;
        return;
    }
    dp[cur][0] = 0;
    dp[cur][1] = 1;
    for(vi it = child[cur].begin();it!=child[cur].end();++it){
        rec(*it);
        dp[cur][0]+=dp[*it][1];
        dp[cur][1]+=dp[*it][0];
    }
    if(dp[cur][0]>dp[cur][1]) dp[cur][1] = dp[cur][0];
}

void form(int cur){
    for(vi it = adj[cur].begin();it!=adj[cur].end();++it){
        if(*it==par[cur]) continue;
        child[cur].push_back(*it);
        par[*it] = cur;
        form(*it);
    }    
}
void print(){
    for(int x = 0;x<num;x++){
        printf("%d %d\n",dp[x][0],dp[x][1]);
    }
}

int main(){
    freopen("vacation.in","r",stdin);
    freopen("vacation.out","w",stdout);
    init();
    scanf("%d",&num);
    int a,b;
    for(int x = 0;x<num-1;x++){
        scanf("%d%d",&a,&b);
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    par[0] = 0;
    form(0);
    rec(0);
    printf("%d\n",dp[0][1]);

}
