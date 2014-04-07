#include <cstdio>
#include <iomanip>
#include <iostream>
#define MAX 100100

using namespace std;
typedef long double ld;

int arr[MAX];
int num;
ld sum = 0;
ld low = 10000;
ld val[MAX];
ld dp[MAX];

ld greatest(ld one, ld two){
    if(one>two) return one;
    else return two;
}

ld greatest(ld one, ld two, ld thr){
    return greatest(greatest(one,two),thr);
}

int main(){
    freopen("sabotage.in","r",stdin);
    freopen("sabotage.out","w",stdout);
    scanf("%d",&num);
    for(int x = 0;x<num;x++){
        scanf("%d",arr+x);
        sum+=arr[x];
        if(x!=0&&x!=num-1&&low>arr[x]) low = arr[x];
    }
    ld start = 0, end = 0;    
    for(int x = 0;x<num;x++) if(arr[x]>end) end = arr[x];
    ld best = 0;
    while(end-start>.0001){
        best = 0;
        dp[0] = 0;
        ld mid = (end+start)/2;
        for(int x = 1;x<num-1;x++) val[x] = arr[x]-mid;
        for(int x = 1;x<num-1;x++){
            dp[x] = greatest(dp[x-1]+val[x],val[x],0.0);
            if(dp[x]>best) best = dp[x];
        }
        if(best==0) best = low-mid;
        if(sum-num*mid-best>=0) start = mid;
        else end = mid;
    }
    cout << fixed << setprecision(3) << (start+end)/2 << endl;    

}
