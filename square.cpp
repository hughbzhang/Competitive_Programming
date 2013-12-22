#include <cstdio>
#define MAX 10000000

using namespace std;

int chain[MAX];
//0 is unknown
//1 is 1
//2 is 89


int next(int origin){
    int start = origin;
    if(chain[start]==1) return 1;
    if(chain[start]==2) return 2;
    int sum = 0;
    while(start>0){
        int cur = start%10;
        start/=10;
        sum+=cur*cur;
    }
    chain[origin] = next(sum);
    return chain[origin];
}

int main(){
    chain[1] = 1;
    chain[89] = 2;
    for(int x = 2;x<MAX;x++){
        next(x);
    }
    int cnt = 0;
    for(int x = 1;x<MAX;x++){
        if(chain[x]==2){
            //printf("%d\n",x);
            cnt++;
        }
    }
    printf("%d\n",chain[4]);
    printf("%d\n",cnt);

    return 0;
}
