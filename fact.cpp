#include <cstdio>

using namespace std;

int ans = 0;
int fact[] = {1,1,2,6,24,120,720,5040,40320,362880};

void check(int origin){
    int start = origin;
    int sum = 0;
    int cur = 0;
    while(start>0){
        cur = start%10;
        start/=10;
        sum+=fact[cur];
    }
    if(sum==origin) ans+=sum;
}


int main(){

    for(int x = 10;x<9999999;x++){
      check(x);
    }
    printf("%d\n",ans);

    return 0;
}
