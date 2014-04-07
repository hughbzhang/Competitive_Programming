#include <cstdio>
#define MAX (1<<12)

using namespace std;
typedef long long ll;

ll dp[12][MAX];
ll mod = 100000000;
ll field[12];
ll valid[MAX];
int e = 0;
int row,col;
ll top;
void print(){
    for(int y = 0;y<row;y++){
        for(int x = 0;x<top;x++){
            printf("%lld ",dp[y][x]);
        }
        printf("\n");
    }
}

int main(){
    freopen("cowfood.in","r",stdin);
    freopen("cowfood.out","w",stdout);
    scanf("%d%d",&row,&col);
    
    for(int y = 0;y<row;y++){
        for(int x = 0;x<col;x++){
            int a;
            scanf("%d",&a);
            if(!a) field[y]+=(1<<x);
        }
    }
    top = (1<<col);
    for(int x = 0;x<top;x++){
        bool flag = true;
        for(int a = 1;a<top;a++){
            if(((1<<a)&x)&&(1<<(a-1)&x)){
                flag = false;
                break;
            }
        }
        if(flag) valid[e++] = x;
    }
    
    for(int x = 0;x<e;x++){
        if(valid[x]&field[0]) dp[0][valid[x]] = 0;
        else dp[0][valid[x]] = 1;
    }
    for(int y = 1;y<row;y++){
        for(int a = 0;a<e;a++){
            if(valid[a]&field[y]) continue;
            for(int b = 0;b<e;b++){
                if((valid[a]&valid[b])==0) dp[y][valid[a]]+=dp[y-1][valid[b]];
                dp[y][valid[a]]%=mod;
            }
        }
    }
    //for(int x = 0;x<e;x++) printf("%lld\n",valid[x]);
    ll ans = 0;
    for(int x = 0;x<top;x++){
        ans+=dp[row-1][x];
        ans%=mod;
    }
    printf("%lld\n",ans);

    //printf("%lld\n%lld\n",field[0],field[1]);
}
