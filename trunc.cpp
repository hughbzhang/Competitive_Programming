#include <cstdio>
#include <iostream>
#include <cmath>
#define MAX 1000000

using namespace std;
typedef long long ll;

int cnt = 0;
ll sum = 0;

bool sieve[MAX];


void init(){
    sieve[0] = true;
    sieve[1] = true;
    int cur = 2;
    bool flag = true;
    while(cur<MAX&&flag){
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
        //printf("cur = %d\n",cur);
    }
}
bool valid(int a){
    if(sieve[a]) return false;
    int num = (int)log10(a);
    int p = pow(10.0,num);
    for(int x = p;x>1;x/=10){
        a%=x;
        if(sieve[a]) return false;
    }
    return true;
}

void construct(int a){
    if(a>MAX) return;
    if(cnt==15) return;
    if(sieve[a]) return;
    if(valid(a)){
        printf("%d\n",a);
        cnt++;
        sum+=a;
    }
    a*=10;
    construct(a+1);
    construct(a+3);
    construct(a+9);
    construct(a+7);
}

int main(){

    init();
    construct(2);
    construct(3);
    construct(5);
    construct(7); 
    printf("COUNT: %d\n",cnt);
    printf("SUM = %lld\n",sum-17);
    return 0;
}





