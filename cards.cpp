#include <cstdio>
#include <string>
#include <iostream>

using namespace std;
typedef long long ll;

ll first,second;

ll ans = -100000000000;
int gap = -1;

int main(){
    cin >> first >> second;
    if(first==0){
        cout << -second*second << endl;
        for(int x = 0;x<second;x++) cout << "x";
        cout << endl;
        return 0;
    }
    if(second==0){
        cout << first*first << endl;
        for(int x = 0;x<first;x++) cout << "o";
        cout << endl;
        return 0;
    }
    for(ll x = 1;x<=first;x++){//number of gaps
        ll cur = x-1+(first-x+1)*(first-x+1);
        ll minus = (x+1)*(second/(x+1))*(second/(x+1))+(second%(x+1))*(1+(second/(x+1))*2);
        if(cur-minus>ans){
            gap = x;
            ans = cur-minus;
        }
    }
    ll width = second/(gap+1);
    ll bonus = second%(gap+1);
    string done = "";
    for(int x = 0;x<gap;x++){
        for(int a = 0;a<width;a++){
            done+='x';
        }
        if(bonus>0){
            done+='x';
            bonus--;
        }
        done+='o';
        if(x==0){
            for(int a = 0;a<first-gap;a++) done+='o';
        }
    }
    for(int a = 0;a<width;a++){
            done+='x';
    }
    cout << ans << endl << done << endl;



    return 0;
}

