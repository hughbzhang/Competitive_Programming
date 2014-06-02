#include <cstdio>
#include <iostream>
#include <vector>
#define MAX 50

using namespace std;

bool vis[MAX];
char letter[MAX];
vector<int> child[MAX];
string target = "bessie";
long long cnt = 0;
int N,M;
void clear(){ for(int x = 0;x<MAX;x++) vis[x]=false;}
void search(int cur, int depth = 5){
    if(vis[cur]) return;
    if(letter[cur]!=target.at(depth)) return;
    if(depth==0){
        cnt++;
        return;
    }
    vis[cur] = true;
    for(int x = 0;x<child[cur].size();x++){
        search(child[cur][x],depth-1);
    }
    vis[cur] = false;
}

int main(){
    freopen("find.in","r",stdin);
    cin >> N >> M;    
    for(int x = 0;x<N;x++) cin >> letter[x];
    int a,b;
    for(int x = 0;x<M;x++){
         cin >> a >> b;
         a--;
         b--;
         child[a].push_back(b);
         child[b].push_back(a);
    }
    long long old = cnt; 
    for(int x = 0;x<N;x++){
         old = cnt;
         clear();
         search(x);

         cout << x << " " <<  cnt-old << endl;
    }
    cout << cnt << endl;
}
