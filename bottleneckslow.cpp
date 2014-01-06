#include <cstdio>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<int>::iterator vi;

int num, queries;

int par[100100];
vector<int> child[100100];
ll gate[100100];
ll cows[100100];

ll DFS(int cur, int mul){
    ll total = cows[cur];
    for(vi it = child[cur].begin();it!=child[cur].end();++it){
        total+=DFS(*it,mul);
    }
    //printf("%lld\n",total);
    return min(mul*gate[cur],total);   
        
}


int main(){
    freopen("bottleneck.in","r",stdin);
    freopen("bottleneck.out","w",stdout);
    scanf("%d%d",&num,&queries);
    int a,b,c;
    for(int x = 1;x<num;x++){
        scanf("%d%d%d",&a,&b,&c);
        a--;
        par[x] = a;
        child[a].push_back(x);
        cows[x] = b;
        gate[x] = c;
    }
    gate[0] = 9999999;
    for(int x = 0;x<queries;x++){
        scanf("%d",&a);
        ll ans = DFS(0,a);
        printf("%lld\n",ans);
    }

}
