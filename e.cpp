#include <cstdio>
#include <iostream>
#include <utility>

#define A first
#define B second
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int main(){

    ll top = 1;
    ll bot = 1;
    ll temp;
    for(int x = 66;x>0;x-=2){
        temp = top+x*bot;
        top = bot;
        bot = temp;
        temp = top+bot;
        top = bot;
        bot = temp;
        temp = top+bot;
        top = bot;
        bot = temp;
        cout << top << "/" << bot << endl;
    
    }
    temp = top+bot;
    top = bot;
    bot = temp;
    top+=2*bot;
    cout << top << "/" << bot << endl;
    return 0;
}
