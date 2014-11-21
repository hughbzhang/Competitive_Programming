#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>

#define A first
#define B second
#define MAX 1000000

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,pii> piii;

ll dp[MAX];
ll tmp[MAX];
piii arr[MAX];
vector<pii> list[MAX];

int N,M;
int a,b,c;
int ans = 0;

int main(){
    scanf("%d%d",&N,&M);
    for(int x = 0;x<M;x++){
        scanf("%d%d%d",&a,&b,&c);
        a--;
        b--;
        arr[x] = piii(c,pii(a,b));
    }
    sort(arr,arr+M);
    int cnt = 0;
    for(int x = 0;x<M;x++){
        if(x!=0&&arr[x].A!=arr[x-1].A) cnt++;
        list[cnt].push_back(arr[x].B);
    }
    cnt++;
    for(int x = 0;x<cnt;x++){
        for(a = 0;a<list[x].size();a++){
            tmp[list[x][a].B] = 0;
        }
        for(a = 0;a<list[x].size();a++){
            tmp[list[x][a].B] = max(tmp[list[x][a].B],dp[list[x][a].A]+1);
        }
        for(a = 0;a<list[x].size();a++) dp[list[x][a].B] = max(dp[list[x][a].B],tmp[list[x][a].B]);
    }
    for(int x = 0;x<N;x++) if(ans<dp[x]) ans = dp[x];
    printf("%d\n",ans);


}

