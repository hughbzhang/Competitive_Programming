#include <cstdio>
#include <iostream>
#define MAX 100100

using namespace std;
typedef long long ll;

ll N,T;

ll pos[MAX];
ll spee[MAX];
ll lane[MAX];
int cnt = 0;


void insert(ll num){
    int s = 0;
    int e = cnt;
    while(s<e){
        int m = s+(e-s)/2;
        if(lane[m]>=num) s = m+1;
        else e = m;
    }
    lane[s] = num;
    if(s==cnt) cnt++;
}
        

int main(){
    freopen("cowjog.in","r",stdin);
    freopen("cowjog.out","w",stdout);
    cin >> N >> T;
    for(int x = 0;x<N;x++){
        cin >> pos[x] >> spee[x];
    }
    lane[cnt++] = pos[0]+spee[0]*T;
    for(int x = 1;x<N;x++){
        insert(pos[x]+spee[x]*T);
    }
    cout << cnt << endl;
}
