#include <iostream>

using namespace std;

int dp[10005];
bool vis[10005];
int N,M;

int rec(int cur, int target){
    if(cur>=target) return cur-target;
    if(cur<=0) return 100000;
    if(dp[cur]!=0) return dp[cur];
    if(vis[cur]) return 100000;
    vis[cur] = true;
    return dp[cur] = 1+min(rec(2*cur,target),rec(cur-1,target));
}

int main(){
    cin >> N >> M;
    cout << rec(N,M) << endl;
}
