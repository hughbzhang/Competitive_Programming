#include <cstdio>

using namespace std;
typedef long long ll;

int cnt = 0;

void comb(int start){
    ll cur = start;
    int index = 1;
    int end = start/2;
    if(start%2==0) end--;
    while(index<=end){
        printf("%lld\n",cur);
        cur*=(start-index);
        index++;
        cur/=index;
        if(cur>1000000){
            cnt+=2*(end-index+1);
            if(start%2==0) cnt++;
            return;
        }
    }
    if(start%2==0){
        cur*=(start-index);
        cur/=(index+1);
        if(cur>1000000) cnt++;
    }
    printf("\n");
}


int main(){
    for(int x = 1;x<=100;x++){
        comb(x);
    }
    printf("%d\n",cnt);
    return 0;
}
