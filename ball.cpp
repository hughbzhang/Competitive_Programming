#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;
typedef long long ll;
ll num;
string in;

int main(){
    cin >> num >> in;
    ll max = pow(2,num)-1;
    ll sum = 0;
    for(int x = 0;x<num;x++){
        if(in.at(x)=='R') sum += pow(2,x);     
    }
    cout << max-sum << endl;
    return 0;

}
