#include <cstdio>
#include <cmath>
#include <set>
#include <algorithm>
#include <iostream>
#include <utility>

#define A first
#define B second
#define MAX 10000000

using namespace std;
typedef long double ld;
typedef pair<ld,ld> pii;
typedef set<pii>::iterator it;

int num;
pii arr[MAX];
set<pii> s;
ld best;
int low = 0;

inline pii rev(pii in){ return pii(in.B,in.A);}
inline ld dist(pii a, pii b){ return sqrt(pow(a.A-b.A,2)+pow(a.B-b.B,2));}


int main(){
    freopen("in.txt","r",stdin); 
    cin >> num;
    ld a,b;
    for(int x = 0;x<num;x++){
        cin >> a >> b;
        arr[x] = pii(a,b);
    }
    sort(arr,arr+num);
    s.insert(rev(arr[0]));
    s.insert(rev(arr[1]));
    best = dist(arr[0],arr[1]);
    for(int x = 2;x<num;x++){
        while(arr[x].A-arr[low].A>=best){
             s.erase(s.find(rev(arr[low])));
             low++;
        }
        s.insert(rev(arr[x]));
        pii now = rev(arr[x]);
        ld mid = arr[x].B;
        it i = s.find(rev(arr[x]));
        ++i;
        while(i!=s.end()&&i->A-best>=mid){
            if(dist(*i,now)<best) best = dist(*i,now);
            ++i;
        }
        i = s.find(rev(arr[x]));
        --i;
        while(best-i->A>=mid){
            if(dist(*i,now)<best) best = dist(*i,now);
            if(i!=s.begin()) ++i;
            else break;
        }
    }
}
