//mobius dp

//searching



#include <cstdio>
#include <vector>

#define MAXN 50

using namespace std;
typedef long long ll;

const int set = (1<<25);

int N,M;
vector<int> child[MAXN];
bool first[set];
bool second[set];
int tog[MAXN];//-1 is nothing 0 is loss 1 is win
ll sum[set];
int half;

bool check(int cur){
    for(int x = 0;x<child[cur].size();x++){
        if(tog[cur]==1&&tog[child[cur][x]]==1) return false;
    }
}

void search(int cur, bool flag){
    if(flag&&cur==half){
        int s = 0;
        for(int x = 0;x<half;x++) s+=tog[x]*(1<<x);  
        first[s] = true;
    }
    if(!flag&&cur==N){
        int s = 0;
        for(int x = half;x<N;x++) s+=tog[x]*(1<<(x-half));  
        second[s] = true;
    }




}


int main(){
    freopen("bessieball.in","r",stdin);
    scanf("%d%d",&N,&M); 
    int a,b;
    for(int x = 0;x<M;x++){
        scanf("%d%d",&a,&b);
        a--;
        b--;
        child[a].push_back(b);
        child[b].push_back(b);
    }
    for(int x = 0;x<MAXN;x++) tog[x] = -1;
    half = N/2;
    search(0,true);
    



    return 0;
}
