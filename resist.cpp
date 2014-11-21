#include <cstdio>
#include <cmath>
#include <iostream>

typedef long long ll;

ll a,b,temp;
ll cnt = 0;

using namespace std;

int main(){
    cin >> a >> b;
    while(a!=0&&b!=0){
        if(b<a){
            temp = b;
            b = a;
            a = temp;
        }
        cnt+=b/a;
        b%=a;
    }
    cout << cnt << endl;
}
