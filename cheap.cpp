#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int N,M,A,B;
int ans = 100000000;
int main(){
    cin >> N >> M >> A >> B;
    if(A*M>B){
        ans = (N/M)*B+(N%M)*A;
    }
    else ans = N*A;
    if(ceil(N/(double)M)*B<ans) ans = ceil(N/(double)M)*B;
    cout << ans << endl;
}
