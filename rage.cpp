#include <cstdio>
#include <iostream>

using namespace std;

int num;
int cnt = 1;
int cur = 0;
int length = 0;
int ans[100];
int ind = 0;
int main(){
    cin >> num;
    int a;
    for(int x = 0;x<num;x++){
        cin >> a;
        length++;
        if(a<0) cur++;
        if(cur==3){
            ans[ind] = length-1;
            ind++;
            length = 1;
            cur = 1;
            cnt++;
        }
    }
    ans[ind] = length;
    ind++;
    cout << cnt << "\n";
    for(int x = 0;x<ind;x++) cout << ans[x] << " ";
    cout << "\n";
    return 0;
}
