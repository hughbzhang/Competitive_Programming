#include <cstdio>
#include <vector>
#include <utility>

#define A first
#define B second

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<int>::iterator vi;

int num;

int par[100100];
vector<int> child[100100];
ll req[100100];
ll speed[100100];

long long ans = 0;

//A is total
//B is speed

pii DFS(int cur){
    ll total = 0;
    ll best = speed[cur];

    for(vi it = child[cur].begin();it!=child[cur].end();++it){
        pii cur = DFS(*it);
        if(cur.B<best) best = cur.B;
        total+=cur.A;
    }
    if(total<req[cur]){
        ans+=((req[cur]-total)*best);
        total = req[cur];
    }
    return pii(total,best);
}


int main(){
    freopen("tdec.in","r",stdin);
    freopen("tdec.out","w",stdout);
    scanf("%d",&num);
    int a,b,c;
    for(int x = 0;x<num;x++){
        scanf("%d%d%d",&a,&b,&c);
        if(a==-1) a = 0;
        else a--;
        par[x] = a;
        req[x] = b;
        speed[x] = c;
        if(a!=0||x!=0) child[a].push_back(x);
    }
    DFS(0);
    printf("%lld\n",ans);

    return 0;
}
