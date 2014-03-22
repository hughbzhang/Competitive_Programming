#include <cstdio>
#include <vector>
#include <iostream>

#define MAX 100000 

using namespace std;
typedef vector<int>::iterator vi;

int num, old, newer;

int par[MAX];
vector<int> chil[MAX];
bool vis[MAX];

void search(int cur,int past){
    if(vis[cur]) return;
    vis[cur] = true;
    par[cur] = past;
    for(vi it = chil[cur].begin();it!=chil[cur].end();++it){
        search(*it,cur);
    }
}

int main(){
    cin >> num >> old >> newer;
    for(int x = 1;x<=num;x++){
        if(x==old) continue;
        cin >> par[x]; 
        chil[x].push_back(par[x]);
        chil[par[x]].push_back(x);
    }
    search(newer,newer);
    for(int x = 1;x<=num;x++){
        if(x==newer) continue;
        cout << par[x] << " ";
    }
    cout << endl;



    return 0;
}
