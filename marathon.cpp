#include <cstdio>
#include <cmath>

#define MAX (1<<18)
#define END (1<<17)

using namespace std;
typedef long long ll;

int N,Q;
char key;
int a,b,c;
ll dist[MAX];
ll SUM[MAX];
ll SAVE[MAX];
ll X[MAX];
ll Y[MAX];

ll max(ll one,ll two){
    if(one<two) return two;
    else return one;
}

ll abs(ll one){
    if(one<0) return -one;
    else return one;
}
ll sum(int left, int right, int l = 0, int r = END, int cur = 1){
    if(left>=r||right<=l) return -1;
    if(left<=l&&r<=right) return SUM[cur];
    int mid = l+(r-l)/2;
    ll first = sum(left,right,l,mid,2*cur);
    ll sec = sum(left,right,mid,r,2*cur+1);
    if(first==-1) first = 0;
    if(sec== -1) sec = 0;
    return first+sec;
}

ll save(int left, int right, int l = 0, int r = END, int cur = 1){
    if(left>=r||right<=l) return -1;
    if(left<=l&&r<=right) return SAVE[cur];
    int mid = l+(r-l)/2;
    return max(save(left,right,l,mid,2*cur),save(left,right,mid,r,2*cur+1));
}
bool addsum(int index, int amount, int l = 0, int r = END, int cur = 1){
    if(index>=r||index<l) return false;
    if(index==l&&index+1==r){
        SUM[cur] = amount;
        return true;
    }
    int mid = l+(r-l)/2;
    if(addsum(index,amount,l,mid,2*cur)||addsum(index,amount,mid,r,2*cur+1)){
        SUM[cur] = SUM[2*cur]+SUM[2*cur+1];
        return true;
    }
    return false;
}

bool addsave(int index, int amount, int l = 0, int r = END, int cur = 1){
    if(index>=r||index<l) return false;
    if(index==l&&index+1==r){
        SAVE[cur] = amount;
        return true;
    }
    int mid = l+(r-l)/2;
    if(addsave(index,amount,l,mid,2*cur)||addsave(index,amount,mid,r,2*cur+1)){
        SAVE[cur] = max(SAVE[2*cur],SAVE[2*cur+1]);
        return true;
    }
    return false;
}
  /* 
void print(){
    for(int x = 1;x<MAX;x++) cout << SAVE[x] << " ";
    cout << endl;
    for(int x = 1;x<MAX;x++) cout << SUM[x] << " ";
    cout << endl;
}*/

ll length(int a, int b){
    return abs(X[a]-X[b])+abs(Y[a]-Y[b]);
}

int main(){
    freopen("marathon.in","r",stdin);
    freopen("marathon.out","w",stdout);
    scanf("%d%d",&N,&Q);
    for(int x = 0;x<N;x++){
        scanf("%lld%lld",X+x,Y+x);
    }
    for(int x = 0;x<N-1;x++){
        dist[x] = length(x,x+1); 
        addsum(x,dist[x]);
    }
    for(int x = 0;x<N-2;x++){
        ll shortcut = abs(X[x]-X[x+2])+abs(Y[x]-Y[x+2]);
        addsave(x,dist[x]+dist[x+1]-shortcut);
    }
    for(int x = 0;x<Q;x++){
        scanf(" %c",&key);
        if(key=='Q'){
            scanf("%d%d",&a,&b);
            a--;
            b--;
            printf("%lld\n",sum(a,b)-save(a,b-1));
        }
        else{
            scanf("%d%d%d",&a,&b,&c);
            a--;
            X[a] = b;
            Y[a] = c;
            if(a>0){
                dist[a-1] = length(a,a-1); 
                addsum(a-1,dist[a-1]);
            }
            if(a<N-1){
                dist[a] =  length(a,a+1); 
                addsum(a,dist[a]);
            }
            if(a>1){
                ll shortcut = length(a,a-2); 
                addsave(a-2,dist[a-1]+dist[a-2]-shortcut);
            }
            if(a>0&&a<N-1){
                ll shortcut = length(a-1,a+1);
                addsave(a-1,dist[a-1]+dist[a]-shortcut);
            }
            if(a<N-2){
                ll shortcut2 = length(a,a+2); 
                addsave(a,dist[a]+dist[a+1]-shortcut2);
            }
        }
    }
}
    
