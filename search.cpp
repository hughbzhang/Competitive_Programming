#include <cstdio>

using namespace std;

int pow[10];
int ans = 0;

void sum(int origin){
    int start = origin;
    int sum = 0;
    while(start>0){
        sum+=pow[start%10];
        start/=10;
    }
    if(sum==origin) ans+=sum;
}


int main(){
    int pro = 1;
    for(int x = 0;x<10;x++){
        pro = 1;
        for(int a = 0;a<5;a++){
            pro*=x;
        }
        pow[x] = pro;
    }
    for(int x = 10;x<1000000;x++){
        sum(x);
    }
    printf("%d\n",ans);
    return 0;
}
