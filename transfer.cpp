#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;
typedef long long ll;

ll arr[1000000];
ll N,T,C;
ll ans = 0;

int main(){
    ios::sync_with_stdio(0);
    cin >> N >> T >> C;
    for(int x = 0;x<N;x++) cin >> arr[x];
    int start = 0;
    int end = 0;
    
    while(end<=N){
        if(end<N&&arr[end]<=T) end++;
        else{
            ans+=max((ll)0,end-start-C+1);
            start = end+1;
            end = start;
        }
    }
    cout << ans << endl;
}
