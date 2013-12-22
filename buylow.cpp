/*
ID: bigfish2
LANG: C++
TASK: buylow
*/

#include <cstdio>
#include <set>

using namespace std;

int day[6000];//prices
int num;
int best = 0;//best overall
long long cnt[6000];//number of subsequences i get from taking this
int pre[6000];//how long it is from here
set<int> vis;//whether ive taken this price b4 in counting unique subsequences

int main(){
    freopen("buylow.in","r",stdin);
//    freopen("buylow.out","w",stdout);
    scanf("%d",&num);
    for(int x = 0;x<num;x++) scanf("%d",day+x);
    for(int y = num-1;y>=0;y--){
        pre[y] = 1;
        cnt[y] = 1;
        vis.clear();
        for(int x = y+1;x<num;x++){
            if(day[y]>day[x]){//if this is lower
                if(pre[x]>=pre[y]){//reset our best
                    pre[y] = pre[x]+1;
                    vis.clear();
                    cnt[y] = 0;
                }
                if(pre[x] == pre[y]-1&&vis.count(day[x])==0){//we'll take it
                    vis.insert(day[x]);
                    cnt[y]+=cnt[x];
                }
            }
        }
        if(pre[y]>best) best = pre[y];
    }
    long long ans = 0;
    vis.clear();
    for(int x = 0;x<num;x++){
        if(pre[x] == best&&vis.count(day[x])==0){
            vis.insert(day[x]);
            ans+=cnt[x];
        }
    }
    for(int x = 0;x<num;x++){
        printf("%lld\n",cnt[x]);
    }
    printf("%d %lld\n",best,ans);

    return 0;
}
