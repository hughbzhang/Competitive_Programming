#include <cstdio>
#include <cmath>
#include <queue>
#include <iostream>
#include <algorithm>
#include <utility>
#define A first
#define B second
#define LARGE (1e7)

#define MAXN 10001
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;

int num;
deque<int> t;
deque<int> d;

int speed = 1;
pii LOC = pii(0,1);
pii TIME = pii(0,1);    

bool same(ld one, ld two){
    if(one<two){
        ld temp = one;
        one = two;
        two = temp;
    }
    if(one-two<0.0000001) return true;
    else return false;
}

ll GCF(ll a, ll b){
    if(a>b){
        ll temp = a;
        a = b;
        b = temp;
    }
    ll c;
    while(a!=0){
        c = b%a;
        b = a;
        a = c;
    }
    return b;
}
pii reduce(pii in){
    ll common = GCF(in.A,in.B);
    in.A/=common;
    in.B/=common;
    return in;
}

pii times(pii a,ll b){
    a.A*=b;
    return a;
}
pii sub(ll a, pii b){
    b.A = a*b.B-b.A;
    return b;
}
pii add(pii one, pii two){
    one = reduce(one);
    two = reduce(two);
    ll top = one.A*two.B+one.B*two.A;
    return pii(top,one.B*two.B);
}
ld val(pii in){
    return in.A/(ld)in.B;
}



int main(){
    ios::sync_with_stdio(false);
    freopen("slowdown.in","r",stdin);
    //freopen("slowdown.out","w",stdout);
    
    cin >> num;
    char in;
    int a;
    for(int x = 0;x<num;x++){
        cin >> in >> a;
        if(in=='T') t.push_back(a);
        else d.push_back(a);
    }
    d.push_back(1000);
    sort(t.begin(),t.end());
    sort(d.begin(),d.end());
    int cur,dist;
    while(!t.empty()||!d.empty()){
        cout << val(TIME) << " " << val(LOC) << endl;
        TIME = reduce(TIME);
        LOC = reduce(LOC);
        if(t.empty()){
            cur = LARGE;
        }
        else{
            cur = t.front();
        }
        if(d.empty()){ dist = LARGE;}
        else{ dist = d.front();}
        int flag = -1;
        if(cur==LARGE) flag = 2;
        else if(dist==LARGE) flag = 1;
        else{
            ld equ = val(add(TIME,(times(sub(dist,LOC),speed))));
            if(same(cur,equ)) flag = 0;
            else if(cur<equ) flag = 1;
            else flag = 2;
        }

        if(flag==0){
            LOC = pii(cur,1);
            TIME = pii(dist,1);
            speed+=2;
            t.pop_front();
            d.pop_front();
        }
        else if(flag==1){
            pii diff = sub(cur,TIME);
//            if(val(diff)<0) cout << "WRONG\n";
            diff.B*=speed;
            LOC = add(LOC,diff);
            TIME = pii(cur,1);
            speed++;
            t.pop_front();
        }
        else{
            TIME=add(TIME,times(sub(dist,LOC),speed));
            if(val(add(TIME,times(sub(dist,LOC),speed)))<0) cout << "WRONG\n"; 
            LOC = pii(dist,1);
            speed++;
            d.pop_front();
        }
        if(val(TIME)<0||val(LOC)<0){
            cout << "BAD " << cur << " " << dist << endl;
            cout << val(TIME) << " " << val(LOC) << endl;
     
            break;
        }

    }
    cout << (ll)round(TIME.A/(ld)TIME.B) << "\n";


    return 0;
}
