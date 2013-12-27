/*
ID: bigfish2
LANG:C++
TASK: fence6
*/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define A first
#define B second
#define MAXN 110
#define LARGE 30000

using namespace std;
typedef vector<int>::iterator it;
typedef pair<int,int> pii;
typedef pair<pii,bool> piii;
typedef vector<pii>::iterator pt;
typedef long long ll;

int num;
vector<int> edge[MAXN];//edge[x] is a vector of edges vertice x can go through
int length[MAXN];//length of edge #x
int con[MAXN][2];//edge 2 connects which to vertices?
int cnt = 0;
vector<pii> list[MAXN];//first the distance then the place;

//Dijkstra
ll ans = LARGE;
bool vis[MAXN];
ll best[MAXN];
priority_queue<piii,vector<piii>,greater<piii> > q;


int insert(vector<int> cur){
    sort(cur.begin(),cur.end());
    for(int x = 0;x<cnt;x++){
        if(cur==edge[x]) return x;
    }
    edge[cnt] = cur;
    cnt++;
    return cnt-1;
}
void print(){
    for(int x = 0;x<cnt;x++){
        printf("VERT %d: ",x);
        for(pt i=list[x].begin();i!=list[x].end();++i){
            printf("%d ",(*i).B);
        }
        printf("\n");
    }
}
void reset(){
    for(int x = 0;x<MAXN;x++){
        vis[x] = false;
        best[x] = LARGE;
    }
    while(!q.empty()) q.pop();
}

ll search(int start){
    int cur = start;
    reset();
    for(pt i = list[cur].begin();i!=list[cur].end();++i){
        q.push(piii(*i,true));
        best[(*i).B]=(*i).A;
    }
    while(!q.empty()){
        piii top = q.top();
        q.pop();
        cur = top.A.B;
        if(vis[cur]) continue;
        vis[cur] = true;
        bool flag = top.B;
        for(pt i = list[cur].begin();i!=list[cur].end();++i){
            int dest = (*i).B;
            int dist = (*i).A;
            if(flag&&dest==start) continue;
            if(best[cur]+dist<best[dest]){
                best[dest] = best[cur]+dist;
                q.push(piii(pii(best[dest],dest),false));
            }    
        }
    }
    return best[start];
}
void DFS(int cur,ll dist,int prior){
    if(vis[cur]){
        if(dist-best[cur]<ans) ans = dist-best[cur];
        return;
    } 
    vis[cur] = true;
    best[cur] = dist;
    for(pt i = list[cur].begin();i!=list[cur].end();++i){
        int dest = (*i).B;
        int dist = (*i).A;
        if(dest==prior) continue;
        DFS(dest,best[cur]+dist,cur);
    }
    vis[cur] = false;
}

int main(){
    freopen("fence6.in","r",stdin);
    freopen("fence6.out","w",stdout);
    scanf("%d",&num);
    int code, size,start,end,junk;
    for(int x = 0;x<num;x++){
        scanf("%d%d%d%d",&code,&size,&start,&end);
        code--;
        length[code] = size;
        vector<int> begin;
        vector<int> last;
        begin.push_back(code);
        last.push_back(code);
        for(int a = 0;a<start;a++){
            scanf("%d",&junk);
            junk--;
            begin.push_back(junk);
        }

        con[code][0] = insert(begin);
        for(int a = 0;a<end;a++){
            scanf("%d",&junk);
            junk--;
            last.push_back(junk);
        }
        con[code][1] = insert(last);
    }
    
    for(int x = 0;x<cnt;x++){
        for(it i=edge[x].begin();i!=edge[x].end();++i){
            start = con[*i][0];
            end = con[*i][1];
            int dest = -1;
            if(x==start) dest = end;
            else if(x==end) dest = start;
            else printf("PROBLEM\n");
            list[x].push_back(pii(length[*i],dest));           
        }
    }
    ll t = search(0);
    for(int x = 0;x<num;x++){
        printf("%d %lld\n",x,best[x]);
    }
    ll ans = LARGE;
    for(int x = 0;x<num;x++){
        ll pos = search(x);
        if(pos<ans) ans = pos;
    }
    printf("%lld\n",ans);
   return 0;
}
