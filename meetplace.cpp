#include <cstdio>
#include <vector>
#define MAX (1<<10)

using namespace std;
typedef vector<int>::iterator vi;

int par[MAX][11];//2^k parent
int height[MAX];
int two[11];
vector<int> child[MAX];
int num,days;

void init(){
    for(int y = 1;y<MAX;y++){
        for(int x = 0;x<11;x++){
            par[y][x] = -1;
        }
    }
    two[0] = 1;
    for(int x = 1;x<11;x++){
        two[x] = two[x-1]*2;
    }
}

void fill(int cur,int depth){
    height[cur] = depth;
    depth++;
    int father = par[cur][0];
    for(int x = 1;x<11;x++){
        par[cur][x] = par[father][x-1];
        father = par[cur][x];
    }
    for(vi it = child[cur].begin();it!=child[cur].end();++it){
        fill(*it,depth);
    }
}
int jump(int cur,int goal){
    //jump to the desired height upward
    int must = height[cur] - goal;
    if(must==0) return cur;
    for(int x = 0;x<11;x++){
        if((1<<x)&must) cur = par[cur][x];
    }
    return cur;
}
int query(int a,int b){
    int goal = min(height[a],height[b]);
    a = jump(a,goal);
    b = jump(b,goal);
    while(a!=b){
        for(int x = 10;x>=0;x--){
            int nextA = par[a][x];
            int nextB = par[b][x];
            if(nextA!=nextB){
                a = nextA;
                b = nextB;
                break;
            }
        }
        a = par[a][0];
        b = par[b][0];
    }
    return a;
}


int main(){
    init();
    freopen("meetplace.in","r",stdin);
    freopen("meetplace.out","w",stdout);
    scanf("%d%d",&num,&days);
    int a,b;
    for(int x = 1;x<num;x++){
        scanf("%d",&a);
        a--;
        par[x][0] = a;
        child[a].push_back(x);
    }
    fill(0,0);
    for(int x = 0;x<days;x++){
        scanf("%d%d",&a,&b);
        a--;
        b--;
        printf("%d\n",query(a,b)+1);
    }

}
