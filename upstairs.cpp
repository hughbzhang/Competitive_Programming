#include <cstdio>
#include <iostream>
#define MAXN 100100



using namespace std;

int N;
int arr[MAXN];
int best = 0;
int ans = -1;

int swap(int in){
    int cur = 0;
    int next = 0;
    next += max(arr[in+1]-arr[in-1],0);
    cur += max(arr[in]-arr[in-1],0);
    next+=max(arr[in]-arr[in+1],0);
    cur += max(arr[in+1]-arr[in],0);
    next += max(arr[in+2]-arr[in],0);
    cur += max(arr[in+2]-arr[in+1],0);
    return next-cur;
}

int main(){
    cin >> N;
    for(int x = 1;x<=N;x++) cin >> arr[x];
    arr[0] = 1006;
    arr[N+1] = 0;
    for(int x = 1;x<N;x++){
        if(swap(x)<best){
            best = swap(x);
            ans = x;
        }
    }
    cout << ans << endl;
}

