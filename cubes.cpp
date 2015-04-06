#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
#include <map>
#include <utility>

#define A first
#define B second
#define MAXN 101000

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

map<pii,int> id;
pii loc[MAXN];
bool vis[MAXN];

priority_queue<int> big;
priority_queue<int,vector<int>, greater<int> > small;

ll ans[MAXN];
ll prm = 1e9+9;

int a,b,M;

bool sup(int block, int past = 0){//can you be supported ATM
    if(block==0) return false;
    int y = loc[block].B-1;
    int x = loc[block].A;
    if(y==-1) return true;

    int one = id[pii(x  ,y)];
    int two = id[pii(x-1,y)];
    int thr = id[pii(x+1,y)];

    if(one!=0&&one!=past) return true;
    if(two!=0&&two!=past) return true;
    if(thr!=0&&thr!=past) return true;
    return false;
}

bool canRem(int block){//can you be removed
    if(block==0) return false;
    int y = loc[block].B+1;
    int x = loc[block].A;
    if(id[pii(x,y)]!=0&&!sup(id[pii(x,y)],block)) return false;
    if(id[pii(x+1,y)]!=0&&!sup(id[pii(x+1,y)],block)) return false;
    if(id[pii(x-1,y)]!=0&&!sup(id[pii(x-1,y)],block)) return false;
    return true;
}
void next(int block){//retrieves next possible blocks to be removed after this one
    int y = loc[block].B;
    int x = loc[block].A;
    if(y==0) return;
    if(canRem(id[pii(x,y-1)])){
        small.push(id[pii(x,y-1)]);
        big.push(id[pii(x,y-1)]);
    }
    if(canRem(id[pii(x-1,y-1)])){
        small.push(id[pii(x-1,y-1)]);
        big.push(id[pii(x-1,y-1)]);
    }
    if(canRem(id[pii(x+1,y-1)])){
        small.push(id[pii(x+1,y-1)]);
        big.push(id[pii(x+1,y-1)]);
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin >> M;
    for(int x = 1;x<=M;x++){
        cin >> a >> b;
        loc[x] = pii(a,b);
        id[pii(a,b)] = x;
    }
    for(int x = 1;x<=M;x++){
        if(canRem(x)){
            big.push(x);
            small.push(x);
      //      cout << x << "PUSH\n";
        }
     //   cout << "SUP " << sup(x) << endl;
    }
    

    for(int x = 0;x<M;x++){
        int cur = -1;
        if(x%2){
            while(!small.empty()){
                cur = small.top();
                small.pop();
                if(vis[cur]||!canRem(cur)) continue;
                break;
            }
        }
        else{
            while(!big.empty()){
                cur = big.top();
                big.pop();
                if(vis[cur]||!canRem(cur)) continue;
                break;
            }
        }
        if(cur==-1) cout << "WRONG" << endl;
        ans[x] = cur-1;
        vis[cur] = true;
        id[loc[cur]] = 0;
        next(cur);
    }
    ll done = 0;
    ll base = 1;
    for(int x = M-1;x>=0;x--){
        done+=ans[x]*base;
        base*=M;
        base%=prm;
        done%=prm;
    }
    //for(int x = 0;x<M;x++) cout << ans[x] << " ";
    //cout << endl;
    cout << done << endl;
}


