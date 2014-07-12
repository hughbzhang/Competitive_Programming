#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <queue>
#define A first
#define B second
#define MAXN 1010
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;

int N,M,K,W;
int total;
ll answer = 0;
priority_queue<piii,vector<piii>,greater<piii> > q;
bool vis[MAXN];
string arr[MAXN];
vector<int> ANS;
ll dist[MAXN][MAXN];

ll diff(int a, int b){
    ll ans = 0;
    for(int x = 0;x<total;x++) ans+=(arr[a].at(x)!=arr[b].at(x));
    return ans;
}

int main(){
    //freopen("in.txt","r",stdin);
    cin >> N >> M >> K >> W;
    total = N*M;
    for(int x = 0;x<K;x++){
        string in;
        for(int a = 0;a<N;a++){
            cin >> in;
            arr[x]+=in;
        }
            
    }
    for(int y = 0;y<K;y++){
        for(int x = y+1;x<K;x++){
            dist[y][x] = W*diff(y,x);
            dist[x][y] = dist[y][x];
        }
    }
    for(int x = 0;x<K;x++) q.push(piii(pii(total,x),-1));
    while(!q.empty()){
        piii cur = q.top();
        q.pop();
        if(vis[cur.A.B]) continue;
        vis[cur.A.B] = true;
        answer+=cur.A.A;
        for(int x = 0;x<K;x++) q.push(piii(pii(dist[cur.A.B][x],x),cur.A.B));
        ANS.push_back(cur.A.B+1);
        ANS.push_back(cur.B+1);
    }
    for(int y = 0;y<K;y++){
        for(int x = 0;x<K;x++){
            //cout << dist[y][x] << " ";
        }
        //cout << endl;
    }
    cout << answer << endl;
    for(int x = 0;x<ANS.size();x++){
        cout << ANS[x];
        if(x%2==0) cout << " ";
        else cout << '\n';
    }
}

