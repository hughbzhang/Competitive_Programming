#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 2009

using namespace std;

vector<int> child[MAX];
int t[MAX];
bool use[MAX];
int arr[MAX];

int N,M;
long long ans = 0;

int cmp(int a,int b){
    return t[a]>t[b]; 
}


int main(){
    cin >> N >> M;
    for(int x = 0;x<N;x++) cin >> t[x];
    int a,b;
    for(int x = 0;x<M;x++){
        cin >> a >> b;
        a--; b--;
        child[a].push_back(b);
        child[b].push_back(a);
    }
    for(int x = 0;x<N;x++) arr[x] = x;
    sort(arr,arr+N,cmp);
    for(int x = 0;x<N;x++){
        for(int a = 0;a<child[arr[x]].size();a++){
            if(!use[child[arr[x]][a]]) ans+=t[child[arr[x]][a]];
        }
        use[arr[x]] = true;
    }
    cout << ans << endl;
}
