#include <cstdio>
using namespace std;

int dp[1000];
int arr[1000];
int max = 1;
int index = 0;
int sum = 0;

int main(){
    freopen("long.in","r",stdin);
    for(int x = 0;x<1000;x++) scanf("%d",arr+x);
    dp[0] = 1;
    for(int x = 1;x<1000;x++){
        if(arr[x]>arr[x-1]) dp[x] = dp[x-1]+1;
        else dp[x] = 1;
        if(dp[x]>max){
            max = dp[x];
            index = x;
        }
    }
    for(int x = 0;x<max;x++){
        sum+=arr[index-x];
    }
    if(sum<0) sum = -sum;
    printf("%d\n",sum);
}
