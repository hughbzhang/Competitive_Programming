#include <cstdio>
#include <iomanip>
#include <iostream>

using namespace std;
typedef long double ld;

int num;
ld C,F,X;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin >> num;
    cout << fixed << setprecision(10);
    for(int x = 1;x<=num;x++){
        cin >> C >> F >> X;
        ld rate = 2, t = 0;
        ld finish = X/rate;//finish now
        ld next = C/rate+(X/(rate+F));//finish after next machine
        while(next<finish){
            t+=C/rate;
            rate+=F;
            finish = X/rate;
            next = C/rate+(X/(rate+F));
        }
        t+=finish;
        cout << "Case #" << x << ": " << t << "\n";
    }

    return 0;
}

