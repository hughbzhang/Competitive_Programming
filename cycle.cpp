#include <cstdio>

using namespace std;

int mod[1000];//everything is 0 anything else is the last time youve seen the mod

void clear(){
    for(int x = 0;x<1000;x++){
        mod[x] = 0;
    }
}

int main(){
    int max = 0;
    int index = 0; 
    int cur = 1;
    int cnt = 0;
    for(int x = 2;x<1000;x++){
        clear();
        cur = 1;
        cnt = 0;
        while(true){
            if(!cur){
                cnt = 0;
                break;
            }
            if(mod[cur]!=0){
                cnt -= mod[cur];
                break;
            }
            mod[cur] = cnt;
            cur*=10;
            cur%=x;
            cnt++;
        }
        if(cnt>max){
            max = cnt;
            index = x;
        }
    }
    printf("%d\n",index);

    return 0;
}
