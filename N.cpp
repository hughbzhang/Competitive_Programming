#include <cstdio>
#include <iostream>

using namespace std;

long long lol;
int num;
long long prime = 1000000007;

int main(){
    cin >> num;
    for(int x = 0;x<num;x++){
        cin >> lol;
        cout << ((lol%prime)*(lol%prime))%prime << endl;
    }
}
