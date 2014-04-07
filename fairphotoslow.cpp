#include <cstdio>
#include <cmath>
#include <algorithm>
#include <utility>
#include <set>
#include <map>


#define A first
#define B second
#define MAXN 100100

using namespace std;

typedef long long ll;
typedef pair<ll,int> pii;

const ll prime = 1000000007;
map<ll,ll> all;
map<ll,bool> vis;

pii arr[MAXN];
int cnt[MAXN][9];//1-8 frgt 0
int temp[9];
ll POLY[9];
int num,K;
ll best = 0;



int main(){
    freopen("fairphoto.in","r",stdin);
    freopen("checker.out","w",stdout);
    scanf("%d%d",&num,&K);
    int b;
    ll a;
    for(int x = 1;x<=num;x++){
        scanf("%lld%d",&a,&b);
        arr[x] = pii(a,b);
    }

    sort(arr+1,arr+num+1);
    for(int y = 1;y<=num;y++){
        for(int x = 1;x<9;x++){
            cnt[y][x] = cnt[y-1][x];
        }
        cnt[y][arr[y].B]++;
    }
    for(int y = 1;y<=num;y++){
//        for(int a = 1;a<9;a++) printf("%d ",cnt[y][a]);
//        printf("\n");
    }
    ll best = 0;
    for(int y = 0;y<=num;y++){
        for(int x = num;x>y;x--){
            bool flag = true;
            int diff = -1;
            int number = 0;
            for(int a = 1;a<9;a++){
                if(cnt[x][a]-cnt[y][a]!=0){
                    number++;
                    if(diff==-1) diff = cnt[x][a]-cnt[y][a];
                    else if(cnt[x][a]-cnt[y][a]!=diff){
                        flag = false;
                        break;
                    }
                }
            }
            if(number>=K&&flag){
                best = max(best,arr[x].A-arr[y+1].A);
//                printf("%d %d\n",x,y+1);
                break;
            }
        }
    }
    printf("%lld\n",best);

    return 0;
}

