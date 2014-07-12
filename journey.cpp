#include <cstdio>
#include <iostream>

using namespace std;

int head[100100];
int N,I,a,b;
long long ans = 0;
int cnt[100100];
bool vis[100100];

int par(int x){
    if(head[x]==x) return x;
    else return head[x] = par(head[x]);
}
void merge(int a, int b){
    a = par(a);
    b = par(b);
    if(a==b) return;
    head[a] = b;
    cnt[b]+=cnt[a];
    cnt[a] = 0;
}

int main(){
    cin >> N >> I;
    int ALL = N;
    for(int x = 0;x<N;x++){
        head[x] = x;
        cnt[x] = 1;
    }
    for(int x = 0;x<I;x++){
        cin >> a >> b;
        merge(a,b);
    }
    for(int x = 0;x<ALL;x++){
        if(vis[par(x)]) continue;
        vis[par(x)] = true;
        N-=cnt[par(x)];
        ans+=cnt[par(x)]*N;
    }
    cout << ans << endl;
}
       
