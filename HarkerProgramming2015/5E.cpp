#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int dp[10100];
int arr[10100];

int prm = 1e9+7;
int N,M;

int main(){
    cin >> N >> M;
    for(int x = 0;x<N;x++) cin >> arr[x];
    dp[0] = 1;  
    sort(arr,arr+N);
    for(int x = 0;x<M;x++){
        for(int a = 0;a<N;a++){
            if(x+arr[a]>M) break;
            dp[x+arr[a]]+=dp[x];
            dp[x+arr[a]]%=prm;
        }
    }
    cout << dp[M]%prm << endl;
}
