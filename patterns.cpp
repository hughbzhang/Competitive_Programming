#include <cstdio>
#define MAX 20200

using namespace std;
typedef unsigned long long ll;

int num,rep;
const ll prime = 1e9+7;

ll X[MAX];
ll hash[MAX];
int list[MAX];

ll h(int start,int length){
    ll ans = 0;
    for(int x = 0;x<length;x++){
        ans+=list[x+start]*X[x];
    }
    return ans;
}

int main(){
    freopen("patterns.in","r",stdin);
    freopen("patterns.out","w",stdout);
    scanf("%d%d",&num,&rep);
    for(int x = 0;x<num;x++) scanf("%d",list+x);
    X[0] = 1;
    hash[0] = 0;
    for(int x = 1;x<=num;x++){
        X[x] = X[x-1]*prime; 
        hash[x] = X[x-1]*list[x-1]+hash[x-1];
    }
    int length = 1;
    bool ok = false;
    int start = 1;
    int end = num;
    while(start<end){
        ok = false;
        length = start+(end-start)/2;
    
        for(int x = 0;x<num-length+1;x++){
            ll cur = h(x,length);
            int cnt = 0;
            
            for(int y = length;y<=num;y++){
                ll pos = hash[y]-hash[y-length];
                //printf("%lld %lld\n",pos,cur);
                if(pos==cur) cnt++;
                cur*=prime;
            }
            //printf("%d\n",cnt);
            if(cnt>=rep){
                ok = true;
                break;
            }
        }
        if(ok) start = length+1;
        else end = length;
    }
    if(start!=end) printf("LOL\n");
    printf("%d\n",start-1);

    return 0;
}
