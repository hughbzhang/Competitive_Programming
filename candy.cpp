#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

int N;
string in;
map<int,int> arr;
long long ans = 0;

int main(){
    //freopen("in.txt","r",stdin);
    cin >> N >> in;
    int total = 0;
    arr[0]++;
    for(int x = 0;x<N;x++){
        if(in.at(x)=='C') total++;
        else total-=2;
        ans += arr[total];
        arr[total]++;
    }
    cout << ans << endl;

}
