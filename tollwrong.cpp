#include <cstdio>
#include <utility>
#include <vector>
#include <queue>

#define A first
#define B second
#define LARGE 10000000

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<pii>::iterator it;
int pastures,paths,queries;

pii adj[250][250];
int tax[300];


/*void search(){
    int cur = 0;
    q.push(piii(pii(tax[cur],cur),tax[cur]));
    while(!q.empty()){
        piii now = q.top();
        q.pop();
        int cost = now.A.A;
        cur = now.A.B;
        int max = now.B;
        for(it i = adj[cur].begin();it!=adj[cur].end();++it){
            int adj = (*it).A;
            int dest = (*it).B;
        }
    }
}*/
int max(int a,int b){
    if(a<b) return b;
    else return a;
}
int dist(int a,int b){return adj[a][b].A+adj[a][b].B;}

int main(){
    freopen("toll.in","r",stdin);
    freopen("toll.out","w",stdout);
    scanf("%d%d%d",&pastures,&paths,&queries);
    for(int x = 0;x<pastures;x++){
        scanf("%d",tax+x);
    }

    for(int x = 0;x<250;x++){
        for(int y = 0;y<250;y++){
            adj[y][x] = pii(LARGE,LARGE);
        }
    }
    int a,b,c;
    for(int x = 0;x<paths;x++){
        scanf("%d%d%d",&a,&b,&c);
        a--;
        b--;
        int cost = max(tax[a],tax[b]);
        if(c+cost<adj[a][b].A+adj[a][b].B) adj[a][b] = pii(c,cost);
        if(c+cost<adj[b][a].A+adj[b][a].B) adj[b][a] = pii(c,cost);
    }
    for(int x = 0;x<pastures;x++){
        adj[x][x] = pii(0,tax[x]);
    }
    for(a = 0;a<pastures;a++){
        //printf("%d\n",adj[1][2].A+adj[1][2].B);
        //printf("%d\n",dist(4,2));
        for(int x = 0;x<pastures;x++){
            for(int y = 0;y<pastures;y++){
                if(x==y) continue;
                int tax = max(adj[x][a].B,adj[a][y].B);
                int costA = adj[x][a].A+adj[a][y].A+tax;
                int costB = adj[x][y].A+adj[x][y].B;
                if(costA<costB){
                    adj[x][y].A = adj[x][a].A+adj[a][y].A;
                    adj[x][y].B = tax; 
                }
                if(costA==costB){
                    if(adj[x][y].B<tax){
                        adj[x][y].A = costA-tax;
                        adj[x][y].B = tax;
                    }
                }
            }
        }
    }
        
    for(int x = 0;x<queries;x++){
        scanf("%d%d",&a,&b);
        a--;
        b--;
        printf("%d\n",adj[a][b].A+adj[a][b].B);
    }
    
    return 0;
}
