#include <cstdio>

using namespace std;

int div[10000];

int main(){
    for(int x = 1;x<10000;x++){
        for(int a = x-1;a>0;a--){
            if(x%a==0) div[x]+=a;
        }
    }
    printf("alive\n");
    int sum = 0;
    for(int x = 1;x<10000;x++){
        if(div[x]>=10000) continue;
        if(div[div[x]]==x&&div[x]!=x){
            printf("%d %d\n",x, div[x]);
            sum+=x;
        }
    }
    printf("%d\n",sum);



    return 0;
}
