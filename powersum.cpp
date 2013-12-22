#include <cstdio>

using namespace std;

long long large[10000000];
long long cur;

int main(){
    long long end;
    scanf("%lld",&end);
    large[0] = 1;
    cur = 0;
    long long carry = 0;
    for(long long a = 1;a<=end;a++){
        carry = 0;
        for(int x = 0;x<=cur;x++){
            large[x]*=a;
            large[x]+=carry; 
            carry=(large[x]/10);
            large[x]%=10;
            if(carry<0) printf("WRONG\n");
        }
        /*if(a==55){
            for(int x = cur;x>=0;x--){
                printf("%lld",large[x]);
            }
            printf("\n");
            printf("%lld\n",carry);
        }*/
        while(carry!=0){
            cur++;
            large[cur] = carry%10;
            carry/=10;

        }
    }
    long long sum = 0;
    for(int x = cur;x>=0;x--){
        sum+=large[x];
    }
    printf("SUM=%lld\n",sum);
    for(int x = cur;x>=0;x--){
        printf("%lld",large[x]);
    }
    printf("\n");
    return 0;
}
