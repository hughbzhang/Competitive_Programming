#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
#include <utility>
#include <algorithm>

#define A first
#define B second
#define MAX 550

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,pii> piii;
typedef vector<piii>::iterator vi;
int M,N,T;

int par[MAX*MAX];
vector<piii> edge;
ll arr[MAX][MAX];
int cnt[MAX*MAX];
int start[MAX*MAX];
ll ans = 0;

ll absolute(ll in){
    if(in<0) return -in;
    else return in;
}

/*void print(){
    for(vi it = edge.begin();it!=edge.end();++it){
        piii cur = *it;
        int dist = cur.A;
        int start = cur.B.A;
        int dest = cur.B.B;
        printf("%d %d %d %d %d\n",dist,start/M,start%M,dest/M,dest%M);
    }
}*/
int dad(int in){
    if(par[in]==in) return in;
    return par[in] = dad(par[in]);
}

bool same(int first, int sec){
    if(dad(first)==dad(sec)) return true;
    else return false;
}
void merge(int one, int two, ll cost){
    if(same(one,two)) return;
    one = dad(one);
    two = dad(two);
    if(cnt[two]<cnt[one]){
        int temp = two;
        two = one;
        one = temp;
    }
    par[one] = two;
    if(cnt[two]<T&&cnt[two]+cnt[one]>=T){
        ans+=start[two]*cost;
    }
    if(cnt[one]<T&&cnt[two]+cnt[one]>=T){
        ans+=start[one]*cost;
    }
    start[two]+=start[one];
    cnt[two]+=cnt[one];
    start[one] = 0;
    cnt[one] = 0;
}

void ok(int cury,int curx, int desty,int destx){
    if(desty<0||desty>=M||destx<0||destx>=N) return;
    int cur = cury*N+curx;
    int dest = desty*N+destx;
    ll dist = absolute(arr[cury][curx]-arr[desty][destx]);
    edge.push_back(piii(dist,pii(cur,dest)));
}
void init(){
    for(int x = 0;x<MAX*MAX;x++){
        par[x] = x;
        cnt[x] = 1;
    }
}


int main(){
    freopen("skilevel.in","r",stdin);
    freopen("skilevel.out","w",stdout);
    init();
    scanf("%d%d%d",&M,&N,&T);
    for(int y = 0;y<M;y++){
        for(int x = 0;x<N;x++){
            scanf("%lld",&arr[y][x]);
        }
    }
    for(int y = 0;y<M;y++){
        for(int x = 0;x<N;x++){
            int in;
            scanf("%d",&in);
            if(in==1){
                start[N*y+x]++;
            }
        }
    }

    for(int y = 0;y<M;y++){
        for(int x = 0;x<N;x++){
            ok(y,x,y+1,x);
            ok(y,x,y,x+1);
        }
    }
    sort(edge.begin(),edge.end());
    for(vi it = edge.begin();it!=edge.end();it++){
        piii now = *it;
        ll dist = now.A;
        int first = now.B.A;
        int second = now.B.B;
        
        merge(first,second,dist);
                
    } 
    printf("%lld\n",ans);
    

}
