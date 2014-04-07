#include <cstdio>
#define TOTAL (1<<16)
#define MAX (TOTAL*2)

using namespace std;

struct node{
    int L;
    int R;
    int best;
    int lazy;
};

node* SEG[MAX];

int max(int a,int b){
    if(a>=b) return a;
    else return b;
}

void down(int cur, int l, int r){
    if(cur>=TOTAL) return;
    if(!(SEG[cur]->lazy)) return;
    if(SEG[cur]->lazy==1){//fill
        SEG[2*cur]->best = 0;
        SEG[2*cur]->L = 0;
        SEG[2*cur]->R = 0;
        SEG[2*cur]->lazy = 1;
        SEG[2*cur+1]->best = 0;
        SEG[2*cur+1]->L = 0;
        SEG[2*cur+1]->R = 0;
        SEG[2*cur+1]->lazy = 1;
    }
    else if(SEG[cur]->lazy==2){//empty
        int dist = (r-l)/2;
        SEG[2*cur]->best = dist;
        SEG[2*cur]->L = dist;
        SEG[2*cur]->R = dist;
        SEG[2*cur]->lazy = 2;
        SEG[2*cur+1]->best = dist;
        SEG[2*cur+1]->L = dist;
        SEG[2*cur+1]->R = dist;
        SEG[2*cur+1]->lazy = 2;
    }
    SEG[cur]->lazy = 0;
}

void up(int cur, int l, int r){
    if(cur>=TOTAL) return;
    int m = (r-l)/2;
    SEG[cur]->R = SEG[2*cur+1]->R;
    SEG[cur]->L = SEG[2*cur]->L;
    if(SEG[cur]->L==m) SEG[cur]->L+=SEG[2*cur+1]->L;
    if(SEG[cur]->R==m) SEG[cur]->R+=SEG[2*cur]->R;
    SEG[cur]->best = max(max(SEG[2*cur]->best,SEG[2*cur+1]->best),SEG[2*cur]->R+SEG[2*cur+1]->L);
}


void update(int left,int right, int cur, int l, int r, bool flag){
    if(cur>=MAX) return;

    if(l>=right||r<=left) return; //OOB

    if(l>=left&&r<=right){
        if(!flag){//empty
            SEG[cur]->L = r-l;
            SEG[cur]->R = r-l;
            SEG[cur]->best = r-l;
            SEG[cur]->lazy = 2;
        }
        else{//fill
            SEG[cur]->L = 0;
            SEG[cur]->R = 0;
            SEG[cur]->best = 0;
            SEG[cur]->lazy = 1;
        }
        return;
    }
    if(cur>=TOTAL) return;
    down(cur,l,r);
    int m = l+(r-l)/2;
    update(left,right,2*cur,l,m,flag);
    update(left,right,2*cur+1,m,r,flag);
    up(cur,l,r);
}

int find(int goal, int cur, int l, int r){
    if(cur>=MAX) return -1;
    if(SEG[cur]->best<goal) return -1;
    if(SEG[cur]->L>=goal) return l;
    down(cur,l,r);
    int m = (r+l)/2;
    int hope = find(goal,2*cur,l,m);
    if(hope!=-1) return hope;
    if(SEG[2*cur]->R+SEG[2*cur+1]->L>=goal) return m-(SEG[2*cur]->R);
    return find(goal,2*cur+1,m,r);
}

void work(int cur, int l, int r){
    if(cur>=TOTAL) return;
    down(cur,l,r);
    int m = l+(r-l)/2;

    work(2*cur,l,m);
    work(2*cur+1,m,r);
    up(cur,l,r);
}

void print(){
    work(1,0,TOTAL);
    for(int x = 0;x<MAX;x++){
        printf("%d %d %d\n",SEG[x]->L,SEG[x]->R,SEG[x]->best);
    }
}

int num, queries;

void init(){
    for(int x = 0;x<MAX;x++) SEG[x] = new node();
    update(0,TOTAL,1,0,TOTAL,0);
}

int main(){
    init();
    freopen("hotel.in","r",stdin);
    freopen("hotel.out","w",stdout);
    scanf("%d%d",&num,&queries);
    update(num,TOTAL,1,0,TOTAL,1);
    int a,b,c;
    for(int x = 0;x<queries;x++){
        scanf("%d",&a);
        if(a==1){
            scanf("%d",&b);
            int start = find(b,1,0,TOTAL);
            printf("%d\n",start+1);
            if(start!=-1) update(start,start+b,1,0,TOTAL,1);
            if(start<-1) printf("WRONG\n");
        }
        else{
            scanf("%d%d",&b,&c);
            update(b-1,b+c-1,1,0,TOTAL,0);
        }
    }
    return 0;
}


