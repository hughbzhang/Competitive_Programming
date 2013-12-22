#include <cstdio>
#define LARGE 1000000

using namespace std;

int f[12][3];
int dp[1<<12];//cost for this particular subset
int total[1<<12];//unsolved friendships for this subset
int length;

int recurse(int num){
    if(dp[num]!=-1) return dp[num];
    int best = LARGE;
    for(int x = 0;x<length;x++){
        if(num&(1<<x)){
            int cost = recurse(num-(1<<x));
            total[num] = total[num-(1<<x)];
            if(num&(1<<f[x][0])) total[num]--;
            else total[num]++;
            if(num&(1<<f[x][1])) total[num]--;
            else total[num]++;
            if(num&(1<<f[x][2])) total[num]--;
            else total[num]++;
            cost+=total[num];
            if(cost<best) best = cost;
        }
    }
    return dp[num] = best;
}

int main(){
    freopen("haywire.in","r",stdin);
    freopen("haywire.out","w",stdout);
    scanf("%d",&length);
    for(int x = 0;x<length;x++){
        scanf("%d%d%d",&f[x][0],&f[x][1],&f[x][2]);
    }
    for(int y = 0;y<length;y++){
        for(int x = 0;x<3;x++){
            f[y][x]--;
        }
    }
    for(int x = 0;x<1<<12;x++) dp[x] = -1;
    /*for(int x = 0;x<12;x++){
        dp[1<<x] = 3;
        total[1<<x] = 3;
    }*/
    dp[0] = 0;
    int ans = recurse((1<<length)-1);
    printf("%d\n",ans);
    /*for(int x = 0;x<1<<6;x++){
        printf("%d %d ",dp[x],total[x]);
        for(int a = 0;a<6;a++) printf("%d",!!(x&1<<a));
        printf("\n");
    }*/
    return 0;
}
