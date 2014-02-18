#include <cstdio>

#define MAX 100010

using namespace std;

int num, ans = 0;
int dp[MAX][MAX];//x then h
int hay[MAX];
//dp[x][h] = hay[x]...hay[a] to a max, such that dp[x][h]<=dp[a-1][h-1]

int main(){
    freopen("tower.in","r",stdin);
    freopen("tower.out","w",stdout);
    scanf("%d",&num);
    for(int x = 1;x<=num;x++) scanf("%d",hay+x);
    for(int x = 1;x<=num;x++){
        dp[x][1] = dp[x-1][1]+hay[x];
    }
    ans = num;
    int begin = 1;
    for(int h = 2;h<=num;h++){
        int start = begin-1;
        int total = 0;
        for(int x = begin;x<=num;x++){
            total+=hay[x];
            while(total>dp[start][h-1]){
                start++;
                total-=hay[start];
            }
            if(total==0) begin = x+1;
            dp[x][h] = total;
        }
        if(dp[num][h]==0){
            ans = h-1;
            break;
        }
    }
    printf("%d\n",ans);
    

    return 0;    

}
