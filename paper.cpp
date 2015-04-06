#include <cstdio>
#include <iostream>

using namespace std;
typedef long long ll;

ll A,B,temp;
ll ans = 0;


int main(){
    cin >> A >> B;
    while(B>0){
        ans+=(A/B);
        temp = A%B;
        A = B;
        B = temp;
    }
    cout << ans << endl;
}
