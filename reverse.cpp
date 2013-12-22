#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

ll num = 0;

ll t(ll origin){
    ll start = origin;
    ll next = 0;
    int p = pow(10.0,(int)(log10(origin)));
    while(start>0){
        next+=p*(start%10);
        start/=10;
        p/=10;
    }
    return next;
}

void check(ll a){
    if(a%10==0) return;
    ll sum = a+t(a);
    while(sum>0){
        if(sum%2==0) return;
        sum/=10;
    }
    //cout << a << " " << t(a) << " " << a+t(a) << endl;
    num++;
}

int main(){
    for(ll x = 1;x<1000000000;x++){
        check(x);
    }
     
    cout << num << endl;
    return 0;
}
