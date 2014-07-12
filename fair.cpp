#include <cstdio>
#include <iostream>

#define MAXN 200200

using namespace std;
typedef long long ll;

ll bonus[MAXN];
int par[MAXN];
ll sal[MAXN];
bool wrong[MAXN];
int bad = 0;


int N,Q;
ll a,b;



int main(){
    cin >> N >> Q;
    for(int x = 1;x<N;x++) cin >> par[x];
    for(int x = 0;x<N;x++){
        cin >> sal[x];
        par[x]--;
    }
    for(int x = 0;x<N;x++){
        if(par[x]==-1) continue;
        if(sal[par[x]]<sal[x]){
            wrong[x] = true;
            bad++;
        }
    }
    for(int x = 0;x<Q;x++){
        cin >> a >> b;
        a--;
        if(a!=0){
            bonus[a]+=b;
            if(sal[a]+bonus[a]>sal[par[a]]){
                if(!wrong[a]) bad++;
                wrong[a] = true;
            }
            else{
                if(wrong[a]) bad--;
                wrong[a] = false;
            }
        }
        if(bad>0) cout << "BAD\n";
        else cout << "GOOD\n";
    }
}
