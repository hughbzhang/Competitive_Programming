#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define MAX 10100
#define LARGE 100000000000
#define A first
#define B second

using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;

int N,M,K;
vector<int> child[MAX];
vector<int> par[MAX];
ll dp[MAX][110];
ll choice[MAX];
bool vis[MAX];
priority_queue<pii,vector<pii>,greater<pii> > q;

int main(){
    ios::sync_with_stdio(0);
    freopen("cowsplay.in","r",stdin);
    freopen("cowsplay.out","w",stdout);
    int a,b;
    cin >> N >> M >> K;
    for(int x = 0;x<M;x++){
        cin >> a >> b;
        a--;
        b--;
        child[a].push_back(b);
        par[b].push_back(a);
    }
    for(int x = 0;x<N;x++) dp[x][0] = LARGE; 
    dp[N-1][0] = 0;
    q.push(pii(0,N-1));
    while(!q.empty()){
        int cur = q.top().B;
        q.pop();
        if(vis[cur]) continue;
        vis[cur] = true;
        for(int x = 0;x<par[cur].size();x++){
            if(dp[par[cur][x]][0]>dp[cur][0]+1){
                dp[par[cur][x]][0] = dp[cur][0]+1;
                q.push(pii(dp[par[cur][x]][0],par[cur][x]));
            }
        }
    }

    for(int k = 1;k<=K;k++){
        
        //assuming you interrupt here

        
        for(int x = 0;x<N;x++){
            for(int y = 0;y<child[x].size();y++){
                dp[x][k] = max(dp[x][k],dp[child[x][y]][k-1]+1);
            }
        }


        
        //assuming you don't


        while(!q.empty()) q.pop();
        for(int x = 0;x<N;x++) vis[x] = false;
        for(int x = 0;x<N;x++) choice[x] = LARGE;
        choice[N-1] = 0;
        q.push(pii(0,N-1));
        while(!q.empty()){
            int cur = q.top().B;

            q.pop();

//            cout << "1 = " << choice[0] << " " << cur << endl;
            if(vis[cur]) continue;
            vis[cur] = true;
            for(int x = 0;x<par[cur].size();x++){
                if(max(choice[cur],dp[cur][k])+1<choice[par[cur][x]]){
                     choice[par[cur][x]] = max(choice[cur],dp[cur][k])+1;
                     q.push(pii(choice[par[cur][x]],par[cur][x]));
                }
            }
        }
        for(int x = 0;x<N;x++){
            if(choice[x]>dp[x][k]) dp[x][k] = choice[x];
        }
    }
    //for(int x = 0;x<N;x++) cout << dp[x][K] << endl;

    if(dp[0][K]>=LARGE) cout << "impossible\n";
    else cout << dp[0][K] << endl;




}
