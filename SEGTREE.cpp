#include <cstdio>
#define MAXR (1<<16)
#define MAX (1<<17)

using namespace std;

struct node{
    int pre;//longest prefix
    int suf;//longest suffix
    int best;//longest run
    int lazy;//0 pass down empty 1 pass down full 2 pass nothing
    int left;//left bound
    int right;//right bound
};
int mark = -1;
int rooms,orders;
node SEG[MAX];
int max(int a, int b, int c){
    if(a>b){
        if(a>c) return a;
        else return c;
    }
    else{
        if(b>c) return b;
        else return c;
    }
}

void empty(int cur){//empty the current node
    if(cur>=MAX) return;
    node &me = SEG[cur];
    me.pre = me.right-me.left;
    me.suf = me.right-me.left;
    me.best = me.pre;
    me.lazy = 0;
}
void full(int cur){
    if(cur>=MAX) return;
    node &me = SEG[cur];
    me.pre = 0;
    me.suf = 0;
    me.best = 0;
    me.lazy = 1;
}
void down(int cur){
    if(cur>=MAXR) return;
    node &me = SEG[cur];
    if(me.lazy==2) return;
    else if(me.lazy==1){
        full(2*cur);
        full(2*cur+1);
    }
    else if(me.lazy==0){
        empty(2*cur);
        empty(2*cur+1);
    }
    else printf("PROBLEM\n");
    me.lazy = 2;
}
void up(int cur){
    if(cur>=MAXR) return;
    node &me = SEG[cur];
    node &left = SEG[2*cur];
    node &right = SEG[2*cur+1];
    me.pre = left.pre;
    me.suf = right.suf;
    int half = left.right-left.left;
    if(me.pre==half) me.pre+=right.pre;//if they are the entire right subhalf we have to add in the right prefix too
    if(me.suf==half) me.suf+=left.suf;//same thing
    me.best = max(left.best,right.best,left.suf+right.pre);//best is best on right or best on left or in between
    me.lazy = 2;//not lazy
}

void init(int cur = 1,int l = 0,int r = MAXR){//initialize the array
    if(cur>=MAX) return;
    SEG[cur].left = l;
    SEG[cur].right = r;
    empty(cur);
    SEG[cur].lazy = 2;
    int m = (l+r)/2;
    init(2*cur,l,m);
    init(2*cur+1,m,r);
}
void work(int cur = 1){ //remove laziness
    if(cur>=MAX) return;
    down(cur);
    work(2*cur);
    work(2*cur+1);
}

void print(){
    for(int x = 16;x<MAX;x++){
        node &me = SEG[x];
        printf("NODE %d PRE %d SUF %d BEST %d LAZY %d LEFT %d RIGHT %d\n",x,me.pre,me.suf,me.best,me.lazy,me.left,me.right);
    }
}
void fill(int start, int end, bool tog, int cur = 1){//start and end either remove or fill
    if(cur>=MAX) return;
    node &me = SEG[cur];
    if(me.right<=start||me.left>=end) return;
    if(start<=me.left&&end>=me.right){//completely contained
        if(tog) full(cur);
        else empty(cur);
        return;
    }
    down(cur);
    fill(start,end,tog,2*cur);
    fill(start,end,tog,2*cur+1);
    up(cur);
}
bool find(int length,int cur = 1){
    if(cur>=MAX) return false;
    node &me = SEG[cur];
    if(me.best<length) return false;
    if(me.pre>=length){
        mark = me.left+1;
        fill(me.left,me.left+length,true);
        return true;
    }
    node &left = SEG[2*cur];
    node &right = SEG[2*cur+1];
    down(cur);
    if(find(length,2*cur)) return true;
    if(left.suf+right.pre>=length){
        int m = (me.left+me.right)/2;
        mark = m-left.suf+1;
        fill(m-left.suf,m-left.suf+length,true);
        return true;
    }
    return find(length,2*cur+1);

}


int main(){
    freopen("hotel.in","r",stdin);
    freopen("hotel.out","w",stdout);
    scanf("%d%d",&rooms,&orders);    
    init();
    fill(rooms,MAXR,true);
    int key,a,b;
    for(int x = 0;x<orders;x++){
        scanf("%d",&key);
        if(key==1){
            scanf("%d",&a);
            if(find(a)) printf("%d\n",mark);
            else printf("0\n");
        }
        else{
            scanf("%d%d",&a,&b);
            fill(a-1,a+b-1,false);
        }
    }
    return 0;
}
