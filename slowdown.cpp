#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN (1<<17)

using namespace std;

int number;
int slow[MAXN];
vector<int> adj[MAXN];//adjacency list
int arrive[MAXN];//arrival times A[b] = x means cow arrived at pasture b at time x
int own[MAXN];
int BIT[MAXN];
bool vis[MAXN];

void add(int index, int sum = 1){
    while(index<MAXN){
        BIT[index]+=sum;
        index+=(index&(-index));
    }
}
int find(int index){
    int sum = 0;
    while(index>0){
        sum+=BIT[index];
        index-=(index&(-index));
    }
    return sum;
}



void DFS(int cur = 1){//default start at pasture 1
    if(vis[cur]) return;
    vis[cur] = true;
    slow[cur] = find(arrive[cur]);
    //THIS IS CRUCIAL
    //the number of times you slow down is equal to the number of cows you passed before coming here. In other words, the number of smaller arrival times you passed. How do we count frequencies? BIT OFC. find() will count number of arrival times less than you in log(n) time.

    add(arrive[cur]);//add yourself to the BIT
    
    for(vector<int>::iterator x = adj[cur].begin();x!=adj[cur].end();++x){
        DFS(*x);
        
    }
    add(arrive[cur], -1);//remove yourself from BIT
}


int main(){
    freopen("slowdown.in","r",stdin);
    freopen("slowdown.out","w",stdout);
    scanf("%d",&number);
    int a,b;
    for(int x = 1;x<number;x++){
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int x = 1;x<=number;x++){
        scanf("%d",&a);
        arrive[a] = x; 
        own[x] = a;
    }
    DFS();
    for(int x = 1;x<=number;x++){
        printf("%d\n",slow[own[x]]);
    }
    return 0;
}
