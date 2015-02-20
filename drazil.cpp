#include <cmath>
#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;

ll a,b,s;

int main(){
    ios::sync_with_stdio(0);
    cin >> a >> b >> s;
    if(a<0) a = -a;
    if(b<0) b = -b;
    if(a+b<=s&&(a+b)%2==(s%2)) printf("Yes\n");
    else printf("No\n");
}
