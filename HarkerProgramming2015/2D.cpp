#include <cstdio>
#include <cmath>
#include <string>
#include <iostream>

using namespace std;
typedef long long ll;

ll ans = 0;
ll cur = 1;
string num;
ll base;
string done = "";
bool neg = false;

int main(){
    cin >> num >> base;
    for(int x = num.length()-1;x>=0;x--){
        ans+=((int)(num.at(x)-'0'))*cur;
        cur*=base;
    }
    if(ans<0){
        neg = true;
        ans = -ans;
    }
    while(ans>0){
        done += (char)(ans%abs(base)+'0');
        ans/=abs(base);
    }
    if(neg) cout << "-"; 
    for(int x = done.length()-1;x>=0;x--) cout << done.at(x);
    //cout << endl;
}
