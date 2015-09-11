#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;
const int MAXN = 1010;

pair<int,int> field[MAXN];

int patches, energyCost;
int neighbors, temp, quality;
int ans = 0;
vector<int> neigh[MAXN];
long long dp[MAXN][MAXN];//first one is current field, second is index of highest quality field levelen
bool vis[MAXN];
queue<pair<int,long long> > q;



void BFS(int loc, int level, long long val){
    while(!q.empty()) q.pop();

    q.push(make_pair(loc,val));

    while(!q.empty()){
        int curLoc = q.front().first;
        long long curVal = q.front().second;
        q.pop();

        if(dp[curLoc][level]>=curVal||dp[curLoc][level-1]>=curVal) continue;
        dp[curLoc][level] = max(curVal,dp[curLoc][level-1]);// set it to the new correct value instead of 0

        for(int idx = 0;idx<neigh[curLoc].size();idx++){
            q.push(make_pair(neigh[curLoc][idx],curVal-energyCost));
        }
    }
}
 

void DFS(int loc, int level, long long val){
    if(dp[loc][level]>=val) return; // if you have already visited go back, dp should be 0 if not visited
    dp[loc][level] = max(val,dp[loc][level-1]);// set it to the new correct value instead of 0
    if(val<=dp[loc][level-1]) return; // if its not as efficient to visit skip this

    for(int idx = 0;idx<neigh[loc].size();idx++){
        DFS(neigh[loc][idx], level, val-energyCost);//go to the next location and propogatej
//        cout << loc << " " << neigh[loc][idx] << endl;
    }
}
    
void clear(){
    for(int x = 0;x<MAXN;x++) vis[x] = false;
}
void print(){
    for(int y = 0;y<=patches;y++){
        for(int x = 0;x<=patches;x++){
            cout << dp[y][x] << " ";
        }
        cout << endl;
    }
}

int main(){
    freopen("buffet.in","r",stdin);
    freopen("buffet.out","w",stdout);
    ios::sync_with_stdio(0);

    cin >> patches >> energyCost;
    for(int x = 1;x<=patches;x++){
        cin >> quality;
        cin >> neighbors;
        field[x] = make_pair(quality,x);
        for(int a = 0;a<neighbors;a++){
            cin >> temp;
            neigh[x].push_back(temp);
        }
    }
    sort(field+1,field+patches+1);
    for(int level = 1;level<=patches;level++){
        int loc = field[level].second;//field we are at
        int qual = field[level].first;//quality of the field we are at
        BFS(loc,level,dp[loc][level-1]+qual);
//        DFS(loc,level,dp[loc][level-1]+qual);
        for(int a = 1;a<=patches;a++) dp[a][level] = max(dp[a][level],dp[a][level-1]);
   }
   for(int x = 0;x<=patches;x++){
       if(dp[x][patches]>ans) ans = dp[x][patches];
   }
   cout << ans << endl;
}
