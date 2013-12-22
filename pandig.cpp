#include <cstdio>
#include <algorithm>

using namespace std;

int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
long long num[] = {1000000000,100000000,10000000,1000000,100000,10000,1000,100,10,1};

int main(){
    long long count = 0;
    do{
        if(arr[3]%2!=0) continue;
        if((arr[2]+arr[3]+arr[4])%3!=0) continue;
        if(arr[5]%5!=0) continue;
        if((100*arr[4]+10*arr[5]+arr[6])%7!=0) continue;
        if((100*arr[5]+10*arr[6]+arr[7])%11!=0) continue;
        if((100*arr[6]+10*arr[7]+arr[8])%13!=0) continue;
        if((100*arr[7]+10*arr[8]+arr[9])%17!=0) continue;
        
        for(int x = 0;x<10;x++){
            count+=(arr[x]*num[x]);
            printf("%d",arr[x]);
        }
        printf("\n");
              
    }
    while(next_permutation(arr,arr+10));
    printf("%lld\n",count);

    return 0;
}
