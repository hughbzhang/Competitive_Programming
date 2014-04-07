#include <cstdio>
#define MAX 5050

using namespace std;
typedef long long ll;
int tall[MAX];
bool vis[MAX];
int in[MAX];
ll fact[MAX];

int N,K,L;
int arr[MAX];
int e = 0;
ll ans = 0;
ll prime = 1000000007;
int top = -MAX;
int bot = MAX;
void trace(int start,bool dir){
    if(start==0||start==N-1){
        arr[e]++;
        return;
    }
    else{
        if(dir){
            if(tall[start]>tall[start+1]){
                arr[e]++;
                vis[start] = true;
                trace(start+1,dir);
                return;
            }
        }
        else{
            if(tall[start]>tall[start-1]){
                vis[start] = true;
                arr[e]++;
                trace(start-1,dir);
                return;
            }
        }
    }


}
ll choose(){
    ll sum = 0;
    for(int x = 0;x<=e;x++) sum += arr[x];
    ll ans = fact[sum];
    for(int x = 0;x<=e;x++){
        ans/=fact[arr[x]];
    }
    e = 0;
    //printf("%lld\n",ans);
    return ans%prime;
}
int main(){
    scanf("%d%d%d",&N,&K,&L);
    int a,b;
    for(int x = 0;x<K;x++){
        scanf("%d",&a);
        a--;
        in[a] = -1;
    }
    for(int x = 0;x<L;x++){
        scanf("%d",&b);
        b--;
        if(in[b]==-1){
            printf("0\n");
            return 0;
        }
        in[b] = 1;
    }
    tall[0] = 0;
    for(int x = 1;x<N;x++){
        if(in[x]==1&&in[x-1]==1){
            printf("0\n");
            return 0;
        }
        if(in[x]==-1&&in[x-1]==-1){
            printf("0\n");
            return 0;
        }
        if(in[x]==1){
            tall[x] = tall[x-1]+1;
        }
        if(in[x]==-1) tall[x] = tall[x]-1;
        if(in[x]==0){
            if(in[x-1]==1) tall[x] = tall[x-1]-1;
            if(in[x-1]==-1) tall[x] = tall[x-1]+1;
            if(in[x-1]==0) tall[x] = tall[x-1]; 
        }

        if(tall[x]>top) top = tall[x];
        if(tall[x]<bot) bot = tall[x];
    }
    fact[0] = 1;
    fact[1] = 1;
    for(int x = 2;x<500;x++) fact[x] = x*fact[x-1];
    ll cur = N;
    for(int y = top;y>=bot;y--){
        for(int x = 0;x<N;x++){
            if(!vis[x]&&tall[x]==y){
                vis[x] = true;
                arr[e] = 1;
                trace(x+1,true);
                trace(x-1,false);
                e++;
            }
        }
        ans+=choose();
    }
    printf("%lld\n",ans);
}
