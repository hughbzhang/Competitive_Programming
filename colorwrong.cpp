#include <cstdio>
#include <set>
#include <vector>
#define MAX 100010

using namespace std;
typedef vector<int>::iterator vi;

int num;
int queries;
int root;

vector<int> edge[MAX];
int s[MAX];
int dad[MAX];
bool vis[MAX];
int color[MAX];

set<int>* DFS(int cur,int past){
    set<int> * now = new set<int>();
    for(vi it = edge[cur].begin();it!=edge[cur].end();++it){
        if((*it)==past) continue;
        set<int> next = *DFS(*it,cur);
        now->insert(next.begin(),next.end());
    }
    s[cur] = now->size();
    return now;
}


int main(){
    freopen("input.txt","r",stdin);
    scanf("%d%d%d",&num,&queries,&root);
    int a,b;
    for(int x = 0;x<num-1;x++){
        scanf("%d%d",&a,&b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for(int x = 1;x<=num;x++){
        scanf("%d",&a);
        color[x] = a;
    }
    DFS(root,root);
    /*
    int cur = root;
    dad[root] = -1;    
    bool flag = true;
    int gone = -1;
    while(cur!=-1){
        printf("%d\n",cur);
        vis[cur] = true;
        flag = true;
        gone = -1;
        for(int x = edge[cur].size()-1;x>=0;x--){
            if((edge[cur][x])==dad[cur]||vis[edge[cur][x]]){
                continue;
            }
            dad[edge[cur][x]] = cur;
            cur = edge[cur][x];
            flag = false;
            gone = x;
            break;
        }
        if(gone!=-1){

            //printf("%d %lu\n",gone,edge[cur].size());
            edge[cur].erase(edge[cur].begin()+gone,edge[cur].end());
        }
        if(flag){
            if(dad[cur]!=-1) arr[dad[cur]].insert(arr[cur].begin(),arr[cur].end());
            cur = dad[cur];
        }
    }*/



   for(int x = 0;x<queries;x++){
        scanf("%d",&a);
        printf("%d\n",s[a]);
    }
    return 0;
}


