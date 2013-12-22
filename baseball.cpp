#include <algorithm>
#include <cstdio>
#define MAXN 1010

using namespace std;

int cows[MAXN];
int num;
long long cnt = 0;

int main(){
    freopen("baseball.in","r",stdin);
    freopen("baseball.out","w",stdout);
    scanf("%d",&num);
    for(int x = 0;x<num;x++){
        scanf("%d",cows+x);
    }
    sort(cows,cows+num);
    for(int y = 0;y<num;y++){
        for(int x = y+1;x<num;x++){
            int low = lower_bound(cows,cows+num,2*cows[x]-cows[y])-cows;
            int high = upper_bound(cows,cows+num,3*cows[x]-2*cows[y])-cows;
            if(low==num&&cows[low]-cows[x]<cows[x]-cows[y]) continue;
            if(high==num&&cows[high]-cows[x]>2*(cows[x]-cows[y])) high++;
            cnt+=(high-low);
        }
    }
    printf("%lld\n",cnt);
}
