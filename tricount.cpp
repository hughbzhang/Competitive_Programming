#include <cstdio>
#include <algorithm>
#include <cmath>
#define MAXN 100100

using namespace std;
typedef long double ld;
typedef long long ll;

const ld PI = acos(-1.0);

int num;

ld angle[MAXN];
ll total;

ll C(ll in){
    if(in<2) return 0;
    return in*(in-1)/2;
}

int main(){
    freopen("tricount.in","r",stdin);
    freopen("tricount.out","w",stdout);
    scanf("%d",&num);
    total = num*(ll)(num-1)*(num-2)/6;
    int a,b;
    for(int x = 0;x<num;x++){
        scanf("%d%d",&a,&b);
        angle[x] = atan2(b,a);        
        if(angle[x]<0) angle[x]+=2*PI;
    }
    int sweep = 0;
    sort(angle,angle+num);
    ld holder = 0.0;
    for(int x = 0;x<num;x++){
        while(angle[sweep]+holder<angle[x]+PI){
            sweep++;
            if(sweep == num){
                holder = 2*PI;
                sweep = 0;
            }
        }
        ll pos = sweep-x-1;
        if(sweep<=x) pos+=num;
        total-=C(pos);
    }
    printf("%lld\n",total);

    return 0;
}
