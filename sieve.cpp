#include <cstdio>
#include <cmath>
#define MAX 1000000


using namespace std;

bool sieve[MAX];//index x corresponds to 2*x+1 Even numbers are nonexistent


int main(){
    
    int stop = sqrt(MAX);

    for(int x = 1;x<stop;x++){
        if(sieve[x]==false){//we are prime
            int square = 2*x*(x+1);//(2x+1)^2 => 4x^2+4x+1 => 2[2*x*(x+1)]+1
            int val = 2*x+1;
            for(int a = square;a<MAX;a+=val){
                sieve[a] = true;//we are composite
            }
        }
    }
    return 0;
}
