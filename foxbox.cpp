#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int arr[110];
int N[110];
int num;
int start = 0;

int main(){
    cin >> num;
    for(int x = 1;x<=num;x++) cin >> arr[x];
    for(int x = 0;x<110;x++) N[x] = x+1;
    N[num] = -1;
    
    sort(arr+1,arr+num+1);
    int ans = 0;
    while(N[0]!=-1){
        ans++;
        int cur = N[0];
        int prev = 0;
        int max = 0;
        while(cur!=-1){
            if(arr[cur]>=max){
                max++;
                N[prev] = N[cur];
            }
            else prev = cur;
            cur = N[cur];
        }
    }
    cout << ans << endl;
    return 0;
}
