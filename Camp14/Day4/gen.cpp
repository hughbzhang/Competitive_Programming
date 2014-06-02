#include <cstdio>
#include <cstdlib>
#include <ctime>

int main(){
    freopen("four.in","w",stdout);
    srand(7);
    long long all = 1e18;
    for(int x = 0;x<200;x++){
        printf("%lld\n",all-x);
    }
}
