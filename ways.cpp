#include <cstdio>
#include <iostream>
#include <map>
#define MAXN (1<<20)

using namespace std;
typedef long long ll;

int N;
ll arr[MAXN];
ll pre[MAXN];
map<ll,int> all;
ll ans = 0;

int main(){
    //freopen("in.txt","r",stdin);
    scanf("%d",&N);
    for(int x = 0;x<N;x++){
        scanf("%I64d",arr+x);
        pre[x+1] = pre[x]+arr[x];
        all[pre[x+1]]++;
    }
    for(int x = 1;x<N-1;x++){
        if(pre[x]*3==pre[N]){
            if(pre[x]==0) ans-=2;//dont count yourself and the end
            ans+=all[pre[x]*2];
        //    cout << ans << endl; 
        }
        all[pre[x]]--;
    }
    printf("%I64d\n",ans);
}
