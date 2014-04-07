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
    freopen("checker2.out","w",stdout);
    scanf("%d%d",&num,&K);
    int b;
    ll a;
    for(int x = 0;x<num;x++){
        scanf("%lld%d",&a,&b);
        arr[x] = pii(a,b);
    }

    sort(arr,arr+num);
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
    int temp[9];
    for(int y = 0;y<num;y++){
        for(int x = num-1;x>y;x--){
            for(int a = 1;a<9;a++) temp[a] = 0;
            for(int a = y;a<=x;a++){
                temp[arr[a].B]++;
            }
            int number = 0;
            int first = -1;
            bool flag = true;
            for(int a = 1;a<9;a++){
                if(temp[a]!=0){
                    if(first==-1) first = temp[a];
                    else if(first!=temp[a]){
                        flag = false;
                        break;
                    }
                    number++;
                }
            }
            if(number>=K&&flag) best = max(best,arr[x].A-arr[y].A);
        }
    }
    printf("%lld\n",best);

    return 0;
}

