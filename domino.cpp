#include <cstdio>
#include <iostream>
#include <string>


using namespace std;

int num;
string in;
int ans = 0;
int main(){
    cin >> num;
    cin >> in;
    int left = -10000;
    int right = -10000;
    bool go = false;
    bool first = true;
    for(int x = 0;x<num;x++){
        if(first&&in.at(x)=='.') ans++;
        if(go&&in.at(x)=='.') ans++;
        if(in.at(x)=='L'){
            if(first) ans-=x;
            first = false;
            left = x;
            go = true;
            if(right>=0&&((left-right)%2==0)) ans++;
        }
        else if(in.at(x)=='R'){
            first = false;
            right = x;
            go = false;
        }
    }
    cout << ans << endl;
}
