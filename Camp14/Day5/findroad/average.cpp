#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    freopen("gray.txt","r",stdin);
    long double a,b,c;
    long double A = 0, B = 0, C = 0;
    for(int x = 0;x<20;x++){
        cin >> a >> b >> c;
        A+=a;
        B+=b;
        C+=c;
    }
    cout << A/(double)20 << " " << B/(double)20 << " " << C/(double)20 << endl;
}
