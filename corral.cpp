#include <cstdio>
#include <utility>
#include <algorithm>

#define A first
#define B second

using namespace std;
typedef pair<int,int> pii;


int C,M,cnt = 0;

pii temp[100100];
pii list[100100];
int child[100100];
int vis[100100];
int dist[100100];
int begin = 0;

int cmp(pii one, pii two){
    if(one.A<two.A) return 1;
    if(one.A>two.A) return 0;
    else return two.B<one.B;
    
}

int DFS(int cur,int mark,int cost){
    if(vis[cur]==mark) return cost-dist[cur];
    else if(vis[cur]!=0) return 100000;
    vis[cur] = mark;
    dist[cur] = cost;
    return DFS(child[cur],mark,cost+1);
}

int main(){
    freopen("corral.in","r",stdin);
    freopen("corral.out","w",stdout);
    scanf("%d%d",&C,&M);
    int a,b;

    for(int x = 0;x<M;x++){
        scanf("%d%d",&a,&b);
        temp[x] = pii(a,a+b);
    }
    sort(temp,temp+M,cmp);
    list[0] = temp[0];
    cnt++;
    for(int x = 1;x<M;x++){
        if(temp[x].B>list[cnt-1].B){
            list[cnt] = temp[x];
            cnt++;
        } 
    }
    int lol = 0;
    while(lol<cnt&&list[lol].B+C<=list[cnt-1].B) ++lol;
    for(int x = 0;x<cnt-lol;x++){
        list[x] = list[x+lol];
    }
    cnt-=lol;
    int cur = 0;
    int index = -1;
    int max = 0;
    int holder = 0;
    for(int x = 0;x<cnt;x++){
        while(list[cur].A+holder<=list[x].B){
            ++cur;
            if(cur==cnt){
                cur = 0;
                holder = C;
            }
        }
        if(cur) child[x] = cur-1;
        else child[x] = cnt-1;
    }
    for(int x = 0;x<cnt;x++){
        printf("%d START: %d END: %d CHILD: %d\n",x,list[x].A,list[x].B%C,child[x]);
    }
    int mark = 1;
    int ans = 1000000;
    for(int x = 0;x<cnt;x++){
        if(!vis[x]){
            begin = list[x].A;            
            int pos = DFS(x,mark,1);
            if(pos!=1&&ans>pos) ans = pos;
            mark++; 
        }
    }
    printf("%d\n",ans);

}
