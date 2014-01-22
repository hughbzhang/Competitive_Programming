#include <cstdio>

using namespace std;

int num;
int min = 101;
int max = -1;
long long ans = (1e9);
int arr[1010];
int main(){
    freopen("skidesign.in","r",stdin);
    freopen("skidesign.out","w",stdout);
    scanf("%d",&num);
    int a;
    for(int x = 0;x<num;x++){
        scanf("%d",&arr[x]);
        if(arr[x]>max) max = arr[x];
        if(arr[x]<min) min = arr[x];
    }
    int diff = max-min-17;
    if(diff<=0){
        printf("0\n");
        return 0;
    }
    int bot;
    int top;
    for(int x = 0;x<=diff;x++){
        bot = min+x;
        top = max-diff+x;
        long long pos = 0;
        for(int a = 0;a<num;a++){
            if(arr[a]<bot){
                pos+=(bot-arr[a])*(bot-arr[a]);
            }
            if(arr[a]>top){
                pos+=(arr[a]-top)*(arr[a]-top);
            }
        }
        if(pos<ans) ans = pos;
    }
    printf("%lld\n",ans);

    return 0;


}
