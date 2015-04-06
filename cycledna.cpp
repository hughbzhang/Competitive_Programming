#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

int arr[26];
int N;
string in;
int key[4] = {0,2,6,19};
int best = 0;
int cnt = 0;
ll prm = 1e9+7;
ll ans = 1;

int main(){
    cin >> N >> in;
    for(int x = 0;x<N;x++){
        arr[in.at(x)-'A']++;
    }
    for(int x = 0;x<4;x++){
        if(arr[key[x]]>best){
            best = arr[key[x]];
            cnt = 1;
        }
        else if(arr[key[x]]==best) cnt++;
    }
    for(int x = 0;x<N;x++){
        ans*=cnt;
        ans%=prm;
    }
    cout << ans << endl;
        
}
    
