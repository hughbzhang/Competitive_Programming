#include <cstdio>
#include <iostream>

using namespace std;

int N;
int cnt = 0;
int ans = 0;

int main(){
    cin >> N;
    int temp;
    for(int x = 0;x<N;x++){
        cin >> temp;
        if(temp>0) cnt+=temp;
        else{
            if(cnt>0) cnt--;
            else ans++;
        }
    }
    cout << ans << endl;
}
