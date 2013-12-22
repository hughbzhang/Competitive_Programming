#include <cstdio>
#include <cmath>
#include <cmath>

using namespace std;

typedef long long ll;

ll next(ll origin){
    ll start = origin;
    ll sum = 0;
    ll p = pow(10.0,((int)log10(origin)));
    while(start>0){
        ll cur = start%10;
        start/=10;
        sum+=p*cur;
        p/=10;
    }
    return sum;
}

int main(){
    
    int cnt = 0;
    for(int x = 1;x<10000;x++){
        bool flag = true;
        ll cur = x+next(x);
        for(int c = 0;c<49;c++){
            ll n = next(cur);
            if(n==cur){
                flag = false;
                break;
            }
            else cur+=n;
        }
        if(flag){
            cnt++;
            printf("%d\n",x);
        }
    }
    printf("%d\n",cnt);

    return 0;
}
