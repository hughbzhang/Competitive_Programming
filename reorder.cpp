#include <cstdio>
#include <iostream>

using namespace std;

int num;

int A[101];
int B[101];
int child[101];
bool vis[101];
int best = -1;
int cnt = 0;


void find(int start){//index of the position
    if(vis[start]) return;
    vis[start] = true;
    if(A[start]==B[start]) return;
    int cur = 1;
    int now = child[A[start]];
    while(now!=start){
        vis[now] = true;
        now = child[A[now]];
        cur++;
    }
    cnt++;
    if(cur>best) best = cur;

}

int main(){
    freopen("reorder.in","r",stdin);
    freopen("reorder.out","w",stdout);
    cin >> num;
    for(int x = 0;x<num;x++) cin >> A[x];
    for(int x = 0;x<num;x++) cin >> B[x];
    for(int x = 0;x<num;x++){
        child[B[x]] = x;
    }
    for(int x = 0;x<num;x++){
        find(x);
    }
    cout << cnt << " " << best << endl; 
}
