/*
ID: bigfish2
LANG: C++
TASK: race3
*/

#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>

#define MAX 55

using namespace std;
typedef vector<int>::iterator vi;
typedef long long ll;

vector<int> adj[MAX];
queue<int> q;
int vis[MAX];
vector<int> una;
vector<int> split;
bool cycle;

int num = 0;

void reset(){
    cycle = false;
    while(!q.empty()) q.pop();
    for(int x = 0;x<MAX;x++){
        vis[x] = false; 
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    freopen("race3.in","r",stdin);
    freopen("race3.out","w",stdout);
    int a;
    cin >> a;
    while(a!=-1){
        num++;
        while(a!=-2){
            adj[num-1].push_back(a);
            cin >> a;
        }
        cin >> a;
    }
    for(int avoid = 1;avoid<num-1;avoid++){
        reset();
        q.push(0);
        vis[avoid] = 1;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            if(vis[cur]) continue;
            vis[cur] = 1;
            for(vi it = adj[cur].begin();it!=adj[cur].end();++it){
                if(!vis[*it]) q.push(*it);    
            }
        }
        for(int x = 0;x<num;x++){
            if(!vis[x]){
                cycle = true;
                una.push_back(avoid);
                break;
            }
        }
        if(cycle){
            bool pos = true;
            vis[avoid] = 0;
            q.push(avoid); 
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                if(vis[cur]==2) continue;
                if(vis[cur]==1){
                    pos = false;
                    break;
                }
                vis[cur] = 2;
                for(vi it = adj[cur].begin();it!=adj[cur].end();++it){
                    q.push(*it);    
                }
            }
            if(pos) split.push_back(avoid);
        }
                
    }
    cout << una.end()-una.begin();
    for(vi it = una.begin();it!=una.end();++it){
        cout << " " << *it;
    }
    cout << "\n";
    cout << split.end()-split.begin();
    for(vi it = split.begin();it!=split.end();++it){
        cout << " " << *it;
    }
    cout << "\n";

    /*for(int x = 0;x<num;x++){
        for(vi it = adj[x].begin();it!=adj[x].end();++it){
            cout << *it << " ";
        }
        cout << "\n";
    }*/
}
