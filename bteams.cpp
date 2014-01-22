#include <cstdio>
#include <algorithm>
#define LARGE (1e7)

using namespace std;

int arr[12];
int order[] = {0,0,0,1,1,1,2,2,2,3,3,3};
int ans = LARGE;
int score[4];

int main(){
    freopen("bteams.in","r",stdin);
    freopen("bteams.out","w",stdout);
    for(int x = 0;x<12;x++){
        scanf("%d",&arr[x]);
    }
    sort(arr,arr+12);
    
    do{
        for(int x = 0;x<4;x++) score[x] = 0;
        for(int x = 0;x<12;x++) score[order[x]]+=arr[x];
        int min = LARGE;
        int max = 0;
        for(int x = 0;x<4;x++){
            if(score[x]<min) min = score[x];
            if(score[x]>max) max = score[x];
        }
        if(max-min<ans) ans = max-min;


    }while(next_permutation(order,order+12));
    printf("%d\n",ans);

    return 0;
}
