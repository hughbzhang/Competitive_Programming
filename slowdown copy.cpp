#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long double ld;
typedef long long ll;

int num;

ll T[10001];
ll D[10001];
int tcnt = 0;
int dcnt = 0;
ld dist = 0;
ld t = 0;
int speed = 1;

int main(){
    freopen("slowdown.in","r",stdin);
    freopen("slowdown.out","w",stdout);
    cin >> num;
    for(int x = 0;x<num;x++){
        char in;
        ll next;
        cin >> in >> next;
        if(in=='T'){
            T[tcnt] = next;
            tcnt++;
        }
        else{
            D[dcnt] = next;
            dcnt++;
        }

    }
    sort(D,D+dcnt);
    sort(T,T+tcnt);
    D[dcnt] = 1000;
    dcnt++;
    T[tcnt] = (1e13);
    int curD = 0;
    int curT = 0;
    while(curD<dcnt||curT<tcnt){
        ld nextT = (D[curD]-dist)*speed;
        if(t+nextT>T[curT]){
            dist += (T[curT]-t)/speed;
            t = T[curT];
            speed++;
            curT++;
        }
        else{
            t+= (D[curD]-dist)*speed;
            dist = D[curD];
            speed++;
            curD++;
        }



    }
    ll ans = round(t);
    cout << ans << endl;



    return 0;
}
