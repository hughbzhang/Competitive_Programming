#include <cstdio>

using namespace std;

bool cycle[10000];

void clear(){
    for(int x = 0;x< 10000;x++) cycle[x] = false;
}
long long cnt = 10000;

void run(int x){
    clear();
    int cur = x;
    while(!cycle[cur]){
        cycle[cur] = true;
        cur +=x;
        cur%=10000;
        cnt++;
    }
}


int main(){
    for(int x = 2;x<10000;x++){
        run(x);
    }
    printf("%lld\n",cnt);
}
