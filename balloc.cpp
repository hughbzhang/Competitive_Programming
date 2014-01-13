#include <cstdio>
#include <utility>
#include <algorithm>
#define MAX (1<<18)
#define MAXN (1<<17)
#define INF (1e7)
#define A first
#define B second
using namespace std;
typedef pair<int,int> pii;

int stalls, reqs, ans = 0;

int rem[MAX];
int lazy[MAX];
pii orders[MAX];

int min(int one, int two){
    if(one<=two) return one;
    else return two;
}

void up(int cur, int left, int right){
    if(cur>=MAXN) return;
    rem[cur] = min(rem[2*cur],rem[2*cur+1]);
}

void down(int cur,int left,int right){
    if(!lazy[cur]) return;
    if(cur>=MAXN) return;//no children
    rem[2*cur]-=lazy[cur];
    rem[2*cur+1]-=lazy[cur];
    lazy[2*cur]+=lazy[cur];
    lazy[2*cur+1]+=lazy[cur];
    lazy[cur] = 0;
    //down propogation
}
void work(int cur = 1, int left = 0, int right = MAXN){
    if(cur>=MAX) return;
    down(cur,left,right);
    int mid = left+(right-left)/2;
    work(2*cur,left,mid);
    work(2*cur+1,mid,right);
    up(cur,left,right);
}
void add(int l,int r, int cur = 1, int left = 0, int right = MAXN){
    if(left>r||right<=l) return; 
    if(left>=l&&right-1<=r){//if inside
        lazy[cur]++;
        rem[cur]--;
        return;
    }
    down(cur,left,right);
    int mid = left+(right-left)/2;
    add(l,r,2*cur,left,mid);
    add(l,r,2*cur+1,mid,right);
    up(cur,left,right);
}

bool check(int l, int r, int cur = 1, int left = 0, int right = MAXN){
//    printf("%d %d\n",left,right);
    if(left>r||right<=l){
        return true;//if out of bounds
    }
    if(left>=l&&right-1<=r){//if inside
        if(rem[cur]==0) return false;//if no left
        return true;
    }
    down(cur,left,right);
    int mid = left+(right-left)/2;
    bool one = check(l,r,2*cur,left,mid);
    bool two = check(l,r,2*cur+1,mid,right);
    up(cur,left,right);
    return one&&two;
}

void print(){
    work();
    for(int x = 1;x<MAX;x++){
        printf("%d\n",rem[x]);
    }
    printf("\n");
}

int main(){
    freopen("balloc.in","r",stdin);
    freopen("balloc.out","w",stdout);
    scanf("%d%d",&stalls,&reqs);
    for(int x = 0;x<stalls;x++){
        scanf("%d",&rem[x+MAXN]);
    }
    for(int x = stalls+MAXN;x<MAX;x++){
        rem[x] = INF;
    }
    work();
    int a,b;
    for(int x = 0;x<reqs;x++){
        scanf("%d%d",&a,&b);
        orders[x] = pii(b-1,a-1);        
    }    
    sort(orders,orders+reqs);
    for(int x = 0;x<reqs;x++){
        if(check(orders[x].B,orders[x].A)){
            add(orders[x].B,orders[x].A);
            ans++;
        }
    }
    printf("%d\n",ans);
}
