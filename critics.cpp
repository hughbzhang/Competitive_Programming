#include <cstdio>
#include <iostream>

using namespace std;

int N,K;
int arr[1000000];
int num[1000000];

int main(){
    cin >> N >> K;
    int cnt = 1;
    cin >> arr[0];
    for(int x = 1;x<N;x++){
        cin >> arr[cnt];
        if(arr[cnt]!=arr[cnt-1]) cnt++;
    }
    num[arr[0]]++;
    num[arr[cnt-1]]++;
    for(int x = 1;x<cnt-1;x++){
        if(arr[x-1]==arr[x+1]) num[arr[x]]+=2;
        else num[arr[x]]++; 
    }
    int ans = 0;
    int best = 0;
    for(int x = 1;x<=K;x++){
        if(num[x]>best){
            best = num[x];
            ans = x;
        }
    }
    cout << ans << endl;
    return 0;

}
