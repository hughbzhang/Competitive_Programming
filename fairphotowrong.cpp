#include <cstdio>
#include <algorithm>
#include <utility>
#include <set>
#include <map>


#define A first
#define B second
#define MAXN 100100

using namespace std;

typedef long long ll;
typedef pair<ll,int> pii;

const ll prime = 1000000007;
map<ll,ll> all;
map<ll,bool> vis;

pii arr[MAXN];
int cnt[9];//1-8 frgt 0
int temp[9];
ll POLY[9];
int num,K;
ll best = -1;

ll trans(){
    int low = MAXN;
    int number = 0;
    for(int x = 1;x<9;x++){
        if(cnt[x]!=0&&cnt[x]<low) low = cnt[x];
        if(cnt[x]!=0) number++;
    }
    if(number<=1) low = 0;
    for(int x = 1;x<9;x++){
        if(cnt[x]==0) temp[x] = 0;
        else temp[x] = cnt[x]-low;
    }
    ll ans = 0;
    for(int x = 1;x<9;x++){
        ans+=POLY[x]*temp[x];
    }
    //for(int x = 1;x<9;x++) printf("%d ",temp[x]);
    //printf("\n");
    return ans;
}

int main(){
    POLY[0] = prime;
    for(int x = 1;x<9;x++) POLY[x] = POLY[x-1]*prime;
    freopen("fairphoto.in","r",stdin);
    freopen("fairphoto.out","w",stdout);
    scanf("%d%d",&num,&K);
    int b;
    ll a;
    for(int x = 0;x<num;x++){
        scanf("%lld%d",&a,&b);
        arr[x] = pii(a,b);
    }
    sort(arr,arr+num);
    vis[0] = true;
    all[0] = -1;

    for(int x = 0;x<num;x++){
        cnt[arr[x].B]++;
        //increment current
        int pos = 0;
        for(int a = 1;a<9;a++) if(cnt[a]>0) pos++;
        //if < k continue
        //STILL HAVE TO ADD TO HASH TABLE
        //printf("%d\n",x);
        ll ans = trans();
        //HASH IT
        if(vis[ans]){
            if(pos>=K) best = max(best,arr[x].A-arr[all[ans]+1].A);
//            printf("%d %lld\n",x,all[ans]+1);    
        }
        else{
            vis[ans] = true;
            all[ans] = x;
        }
//        printf("%lld\n",ans);
        //find if exists
        //else add to table
    }
    printf("%lld\n",best);

    return 0;
}


