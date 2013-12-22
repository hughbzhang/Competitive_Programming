#include <cstdio>
#include <queue>
#include <algorithm>
#include <functional>
#include <utility>
#define MAXN 50500
#define A first
#define B second

using namespace std;

typedef pair<int,int> pii;//value then key
typedef priority_queue<pii> maxheap;
typedef priority_queue<pii, vector<pii>, greater<pii> > minheap;
typedef long long ll;

ll money, current = 0;
int cows,coupons, cnt = 0;
int norm[MAXN];//normal price
int dis[MAXN];//discount
int key[MAXN];
bool in[MAXN];
bool coup[MAXN];
maxheap rem;//rem the largest from the group
minheap rev;//rev the most useless coupon (the one that saves the least)
maxheap use;//the best one in your group to use a coupon on

bool compare(int a, int b){
    return dis[a]<dis[b];
}

int main(){
    freopen("coupons.in", "r", stdin);
    freopen("coupons.out","w",stdout);
    scanf("%d%d%lld",&cows,&coupons,&money);
    for(int x = 0;x<cows;x++){
        key[x] = x;
        scanf("%d%d",norm+x,dis+x);
    }
    sort(key,key+cows,compare);
    for(int x = 0;x<coupons;x++){//MAKE SURE THAT YOU LOOK AT THE DEGENERATE CASE OF WHEN THE MONEY RUNS OUT BEFORE THE COUPONS ARE ALL USED
        current+=dis[key[x]];//push the couponed cost to your total
        
        if(current>money){
            printf("%d\n",x);
            return 0;
        }
        coup[key[x]] = true;
        in[key[x]] = true;
        rem.push(pii(dis[key[x]],key[x]));//push the cost and id to your rem heap
        rev.push(pii(norm[key[x]]-dis[key[x]],key[x]));//ad the discount to the rev heap
    }
    int cost;
    cnt = coupons;
    int cur;
    bool print = false;
    bool save = false;//extra coupon
    //printf("COUPONS: %d\n",coupons);
    for(int x = coupons;x<cows;x++){
        /* printf("\nCOUNT %d\n",cnt);
        print = false;
        for(int a = 0;a<cows;a++){
            if(coup[a]){
                printf("COUPON AT %d\n",a); 
                print = true;
                break;
            }
        }
        //if(!print) printf("%d\n",x);
        */
        int usesize = use.size();
        //if(usesize>0) printf("usesize = %d USE %d %d\n",usesize,use.top().A,use.top().B);
        while(rem.size()>0&&!in[rem.top().B]) rem.pop();//WE START BY MAINTAINING THE INTEGRITY OF OUR HEAPS
        while(rev.size()>0&&!coup[rev.top().B]) rev.pop();
        while(use.size()>0&&(!in[use.top().B]||coup[use.top().B])) use.pop();
        int remsize = rem.size();
        int revsize = rev.size();
        //printf("remsize = %d REM %d %d\n",remsize,rem.top().A,rem.top().B);
        //printf("revsize = %d REV %d %d\n",revsize,rev.top().A,rev.top().B);
        //printf("IN[0] %d COUP[0] %d\n",in[0],coup[0]); 
        cost = min(norm[key[x]],dis[key[x]]+rev.top().A);//minimum cost of this guy including coupon revoking
        //printf("COST: %d\n", cost);
        //printf("CURRENT: %lld\n",current);
        if(current+cost>money){//we have to throw something out
            if(cost>=rem.top().A) continue;//throw out our guy
            else{//process removing the top
                cnt--;
                cur = rem.top().B;
                in[cur] = false;
                current-=rem.top().A;
                if(coup[cur]){//additional steps to be taken if coupon exists
                   coup[cur] = false;
                   save = true;
                   //save the coupon
                }
            }
        }
        cnt++;
        cur = key[x];
        in[cur] = true;
        current+=cost;
        rem.push(pii(cost,cur));
        if(norm[cur]<=dis[cur]+rev.top().A){
            //coup[cur] = false;//unnecessary
            use.push(pii(norm[cur]-dis[cur],cur));
        }
        else{
            coup[cur] = true;
            coup[rev.top().B] = false;
            //use.push(rev.top());//should be unnecessary
            rev.pop();
        }
        if(save){
            cur = use.top().B;
            if(cur==-1) continue;
            coup[cur] = true;
            save = false;
            current-=use.top().A;
        }
        //ADD OURSELF IN
    }

    printf("%d\n",cnt);

    for(int x = 0;x<cows;x++){
        //if(coup[key[x]]) printf("%d ",key[x]);
    }
    return 0;
}
