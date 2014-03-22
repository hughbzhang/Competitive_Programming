#include <cstdio>
#include <map>
#define MAX 200100

using namespace std;
typedef long long ll;
int num;

int dest[MAX];
int time[MAX];
map<int,int> block;
ll ans = 0;

int main(){
    freopen("boarding.in","r",stdin);
    //freopen("boarding.out","w",stdout);
    scanf("%d",&num);
    for(int x = num-1;x>=0;x--){
        scanf("%d%d",&dest[x],&time[x]);
    }
    for(int x = 0;x<num;x++){
        int extra = 0;
        for(int a = -x;a<=dest[x];a++){
            if(block[a]-x>0&&block[a]-x>extra) extra = block[a]-x;
            if(a!=0&&block[a-1]<block[a]){
                block[a-1] = (block[a]+1);
                block[a] = 0;
            }
        }
        block[dest[x]] = time[x]+1;
        ll pos = time[x]+extra+dest[x]+x; 
        if(pos>ans) ans = time[x]+extra+dest[x]+x;
        printf("%lld\n",pos);
    }
    printf("%lld\n",ans);
}
