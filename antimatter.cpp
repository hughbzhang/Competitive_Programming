#include <cstdio>
#include <iostream>

using namespace std;
typedef long long ll;

int num;
int arr[1001];
ll dp[20002][1001];
const ll prime = 1e9+7;
ll ans = 0;

void print(){
    for(int y = 9996;y<10005;y++){
        for(int x = 0;x<4;x++){
            cout << dp[y][x] << " ";
        }
        cout << endl;
    }
}

int main(){
    cin >> num;
    for(int x = 0;x<num;x++) cin >> arr[x];
    for(int x = 0;x<num-1;x++){
        dp[10000+arr[x]][x]++;
        dp[10000-arr[x]][x]++;
        for(int y = 0;y<20001;y++){
            if(!dp[y][x]) continue;
            dp[y+arr[x+1]][x+1]+=dp[y][x];
            dp[y-arr[x+1]][x+1]+=dp[y][x];
            dp[y+arr[x+1]][x+1]%=prime;
            dp[y-arr[x+1]][x+1]%=prime;
        }
    }
    dp[10000+arr[num-1]][num-1]++;
    dp[10000-arr[num-1]][num-1]++;
    for(int x = 0;x<num;x++){
        ans+=dp[10000][x];
        ans%=prime;
    }
    //print();
    cout << ans << endl;

    return 0;
}
