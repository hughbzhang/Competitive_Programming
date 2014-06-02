#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <iostream>


using namespace std;

typedef long double ld;
int main(){
    srand(7);
    freopen("in.txt","w",stdout);
    int num = 5000;
    cout << fixed;
    cout << num << "\n";
    ld MAX = 1000000000;
    for(int x = 0;x<2*num;x++){
        ld next = rand()/(ld)(RAND_MAX+1)*MAX;
        if(rand()%2) next = -next;
        cout << next << "\n";
    }

}
