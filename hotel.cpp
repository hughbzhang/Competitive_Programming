#include <cstdio>
#include <functional>
#include <utility>
#define MAXR (1<<16)//over 50000
#define MAX (1<<17)//SEG TREE SIZE
#define A first
#define B second

using namespace std;
typedef pair<int,int> pii;

struct node{
    int pre;//longest prefix
    int suf;//longest suffix
    int cond;//0 if empty 1 if full 2 if mixed
    int best;//longest run in this range
    int first;//index of the start of the best range
    bool lazy;//do you need to pass to children
};

node SEG[MAX];
int rooms,orders;
int token = 0;
pii max(int a,int b, int c){
    if(a>b){
        if(a>c) return pii(a,0);
        else return pii(c,2);
    }
    else{
        if(b>c) return pii(b,1);
        else return pii(c,2);
    }
}

void up(int cur,int l,int r){//propogate up
    node &me = SEG[cur];
    node &right = SEG[2*cur+1];
    node &left = SEG[2*cur];
    int total = (r-l)/2;
    me.pre = left.pre;
    me.suf = right.suf;
    if(me.pre==total) me.pre+=right.pre;
    if(me.suf==total) me.suf+=left.suf;

    pii BEST = max(left.best,right.best,left.suf+right.pre);//best is best on left or best on right or combined pre+suf
    me.best = BEST.A;
    if(BEST.A==0) me.first = -1;
    else if(BEST.B==0) me.first = l;
    else if(BEST.B==1) me.first = r-BEST.A;
    else me.first = (l+r)/2-left.suf;
    if(right.cond==left.cond) me.cond = right.cond;
    else me.cond = 2;//mixed
    if(me.cond==2) me.lazy = false;
    
}
void full(int cur){//propogate a full down to this node
    SEG[cur].pre = 0;
    SEG[cur].suf = 0;
    SEG[cur].cond = 1;
    SEG[cur].best = 0;
    SEG[cur].first = -1;
    SEG[cur].lazy = true;
}
void empty(int cur, int l, int r){//propogate a empty to this node
    SEG[cur].pre = r-l;
    SEG[cur].suf = r-l;
    SEG[cur].cond = 0;
    SEG[cur].best = r-l;
    SEG[cur].first = l;
    SEG[cur].lazy = true;
}
void down(int cur,int l, int r){//call this to propogate down
    if(cur>=MAXR) return;
    if(!SEG[cur].lazy) return;
    SEG[cur].lazy = false;
    int m = (l+r)/2;
    if(SEG[cur].cond==0){
        empty(2*cur,l,m);
        empty(2*cur+1,m,r);
    }
    else if(SEG[cur].cond==1){
        full(2*cur);
        full(2*cur+1);
    }
    else printf("BAD THING\n");
}
// to remove continue dividing until your current range is completely enclosed in the desired range, then be lazy.

void rem(int start,int end, int cur = 1, int l = 0, int r = MAXR){//start and end are the ranges we are looking for
//cur and l and r are the current node info
    if(r<=start||l>=end) return;//if out of bounds
    if(start<=l&&end>=r) empty(cur,l,r);
    else if(cur<=MAXR){
        int m = (l+r)/2;
        down(cur,l,r);//propogate down before calling children
        rem(start,end,2*cur,l,m);
        rem(start,end,2*cur+1,m,r);
        up(cur,l,r);//fix yourself
    }
}
void fill(int start, int end, int cur = 1, int l = 0, int r=MAXR){
    
    if(r<=start||l>=end) return;//if out of bounds  
    
    int length = end-start;
    int m = (l+r)/2;
    if(start<=l&&end>=r) full(cur);
    else if (cur<=MAXR){
        down(cur,l,r);
        fill(start,end,2*cur,l,m);
        fill(start,end,2*cur+1,m,r);
        up(cur,l,r);
    }
}
bool find(int length, int cur = 1,int l = 0, int r = MAXR){
    if(cur>=MAX) return false;
    if(SEG[cur].best<length) return false;//if I don't contain it go back
    if(length<SEG[cur].pre){
//        printf("FIRST: %d\n",l);
        token = l+1; 
        fill(l,l+length);
        return true;
        //success
    }
    if(cur>=MAXR) return false;
    down(cur,l,r);    
    int m = (l+r)/2;
    if(find(length,2*cur,l,m)) return true;
    if(SEG[2*cur].suf+SEG[2*cur+1].pre>=length){
        token = m-SEG[2*cur].suf+1;
  //      printf("FILL: %d\n",m-SEG[2*cur].suf);
        fill(m-SEG[2*cur].suf,m-SEG[2*cur].suf+length);
        return true;
    }
    return find(length,2*cur+1,m,r);
}

void print(){
    for(int x = 1;x<MAX;x++){
        node cur = SEG[x];
        printf("%d: PRE: %d SUF: %d COND: %d BEST: %d FIRST: %d LAZY: %d\n",x,cur.pre,cur.suf,cur.cond,cur.best,cur.first,cur.lazy);
    }
}
void init(int cur = 1,int l = 0,int r = MAXR){
    if(cur>=MAX) return;
    SEG[cur].pre = r-l;
    SEG[cur].suf = r-l;
    SEG[cur].cond = 0;
    SEG[cur].best = r-l;
    SEG[cur].first = l;
    SEG[cur].lazy = false;
    int m = (l+r)/2;
    init(2*cur,l,m);
    init(2*cur+1,m,r);
}
/*struct node{
    int pre;//longest prefix
    int suf;//longest suffix
    int cond;//0 if empty 1 if full 2 if mixed
    int best;//longest run in this range
    int first;//index of the start of the best range
    bool lazy;//do you need to pass to children
};*/
void work(int cur = 1,int l = 0, int r = MAXR){
    if(cur>=MAX) return;
    down(cur,l,r);
    int m = (l+r)/2;
    work(2*cur,l,m);
    work(2*cur+1,m,r);
}



int main(){
    freopen("hotel.in","r",stdin);
    freopen("hotel.out","w",stdout);
    scanf("%d%d",&rooms,&orders);
    int key;
    int a,b;
    init();
    fill(rooms,MAXR);
    
    for(int x = 0;x<orders;x++){
        scanf("%d",&key);
        if(key==1){
            scanf("%d",&a);
            if(find(a)) printf("%d\n",token);
            else printf("0\n");
        }
        else{
            scanf("%d%d",&a,&b);
            rem(a-1,a+b-1);
        }
    }
//    work();
//    print();
    return 0;
}


