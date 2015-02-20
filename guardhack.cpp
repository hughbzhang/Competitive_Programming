#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#define A first
#define B second

using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef long long ll;

piii info[30];
ll ans = -1;
ll N,H;
int a,b,c;

int main(){
        freopen("guard.in","r",stdin);
            freopen("guard.out","w",stdout);
                cin >> N >> H;
                    for(int x = 0;x<N;x++){
                                cin >> a >> b >> c;
                                        info[x] = piii(c,pii(a,b)); //strength, height, weight
                                            }
                        sort(info,info+N);
                            for(ll x = 0;x<(1<<N);x++){
                                        bool ok = true;
                                                ll total = 0;
                                                        ll height = 0;
                                                                ll margin = 1000000000;
                                                                        for(int a = 0;a<N;a++){
                                                                                        if((1<<a)&x){
                                                                                                            if(total>info[a].A){
                                                                                                                                    ok = false;
                                                                                                                                                        break;
                                                                                                                                                                        }
                                                                                                                            height+=info[a].B.A;
                                                                                                                                            margin = min(margin,info[a].A-total);
                                                                                                                                                            total+=info[a].B.B;
                                                                                                                                                                        }
                                                                                                }
                                                                                if(ok&&height>=H){
                                                                                                ans = max(ans,margin);
                                                                                                        }
                                                                                    }
                                if(ans==-1) cout << "Mark is too tall" << endl;
                                    else cout << ans << endl;
}


