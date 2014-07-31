#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
long double ans = 0;
long double arr[200200];

int N,K;

int main(){
    cin >> N >> K;
    for(int x = 0;x<N;x++){
        cin >> arr[x];
    }
    sort(arr,arr+N);
    reverse(arr,arr+N);
    long long all = pow(2,K)-1;
    if(all>N) all = N;
    for(int x = 0;x<all;x++) ans+=arr[x];
    cout << ans << endl;
}
