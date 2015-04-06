#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;


ll B,R;
ll prm = 1e9+7;


int main(){
    cin >> B >> R;
    for(int x = 0;x<=100000;x++){
        ll token = B;
        ll cur = x;
        ll sum = 1;
        while(token>0){
            if((token%2)==1) sum*=cur;
            token/=2;
            cur = cur*cur;
            cur%=prm;
            sum%=prm;
        }
        if(sum==R){
            cout << x << endl;
            return 0;
        }
    }
}
