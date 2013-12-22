#include <cstdio>
#define MAX 1000000

using namespace std;

bool sieve[MAX];
int prime[MAX];
int cnt = 0;

void init(){
    sieve[0] = true;
    sieve[1] = true;
    int cur = 2;
    bool flag = true;
    while(flag){
        flag = false;
        for(int x = 2*cur;x<MAX;x+=cur){
            sieve[x] = true;
        }
        for(int x = cur+1;x<MAX;x++){
            if(!sieve[x]){
                flag = true;
                cur = x;
                break;
            }
        }
    }
    for(int x = 0;x<MAX;x++){
        if(!sieve[x]){
            prime[cnt] = x;
            cnt++;
        }
    }
}

int main(){
    init();
    int best = 0;
    int pri = -1;
    for(int length = cnt;length>0;length--){
        long long pos = 0;
        for(int x = 0;x<length;x++){
            pos+=prime[x];
        }
        for(int start = length;start<cnt;start++){
            pos+=prime[start];
            pos-=prime[start-length];
            if(pos>=MAX) break;
           // printf("here\n");
            if(!sieve[pos]){
                printf("%lld\n",pos);
                return 0;
            }
            //printf("or not\n");
        }
    }



    return 0;
}
