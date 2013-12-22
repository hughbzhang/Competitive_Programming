#include <cstdio>
#define MAX 10000000

using namespace std;

bool sieve[MAX];

void init(){
    sieve[0] = true;
    sieve[1] = true;
    int cur = 2;
    bool flag = true;
    while(flag&&cur<MAX){
        flag = false;
        for(int x = 2*cur;x<MAX;x+=cur){
            sieve[x] = true;
        }
        for(int x = cur+1;x<MAX;x++){
            if(!sieve[x]){
                cur = x;
                flag = true;
                break;
            }
        }
    }
}

int main(){
    init();
    bool flag = true;
    for(int x = 3;x<MAX;x+=2){
        flag = true;
        int square = 0;
        int next = 2*square*square;
        while(next<x){
            
            if(!sieve[x-next]){
                flag = false;
                break;
            }
            square++;
            next = 2*square*square;
        }
        if(flag){
            printf("%d\n",x);
            return 0;
        }
    }
}
