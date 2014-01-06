#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

#define MAXN 10100
#define A first
#define B second

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii>::iterator vi;

int paths,pastures;

int talk[MAXN];
vector<pii> neigh[MAXN];
bool vis[MAXN];
ll cost = 0;
priority_queue<pll,vector<pll>,greater<pll> > q;

int main(){
    ifstream fin ("cheer.in");
    ofstream fout ("cheer.out");
    fin >> pastures >> paths;
    int min = 99999;
    int index = -1;
    for(int x = 0;x<pastures;x++){
        fin >> talk[x];
        if(talk[x]<min){
            index = x;
            min = talk[x];
        }
    }
    for(int x = 0;x<paths;x++){
        int a,b,c;
        fin >> a >> b >> c;
        a--;
        b--;
        neigh[a].push_back(pii(c,b));
        neigh[b].push_back(pii(c,a));
    }
    q.push(pll(talk[index],index));
    while(!q.empty()){
        pll NOW = q.top();
        q.pop();
        ll cur = NOW.B;
        if(vis[cur]) continue;
        cost+=NOW.A;
        vis[cur] = true; 

        for(vi it = neigh[cur].begin();it!=neigh[cur].end();++it){
            q.push(pll((*it).A+(*it).A+talk[cur]+talk[(*it).B],(*it).B));
        } 
    }
    fout << cost << "\n";

    
    return 0;
}
