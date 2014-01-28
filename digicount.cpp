#include <cstdio>

using namespace std;
typedef long long ll;
int cnt[10];
int sec[10];

void resetall(){
    for(int x = 0;x<10;x++){
        cnt[x] = 0;
        sec[x] = 0;
    }
}
void reset(){
    for(int x = 0;x<10;x++) sec[x] = 0;
}

bool test(ll num){
    reset();
    while(num>0){
        sec[num%10]++;
        num/=10;
    }
    for(int x = 0;x<10;x++){
        if(sec[x]!=cnt[x]) return false;
    }
    return true;
}

int main(){
    ll cur = 0;
    bool flag = true;
    while(flag){
        cur++;
        flag = false;
        resetall();
        ll num = cur;
        while(num>0){
            cnt[num%10]++;
            num/=10;
        }
        for(int x = 2;x<7;x++){
            if(!test(x*cur)){
                flag = true;
                break;
            }
        } 
        /*for(int x = 0;x<10;x++){
            printf("%d ",sec[x]);
        }
        printf("\n");*/
    }
    printf("%lld\n",cur);


    return 0;
}
