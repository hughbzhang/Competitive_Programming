#include <cstdio>
#define MAX (1<<17)

using namespace std;

int SEG[2*MAX];
bool LAZY[2*MAX];

void lazy(int cur,int f, int b){
    SEG[cur] = b-(f+SEG[cur]);//toggling reverses all on and off
    LAZY[cur] = !LAZY[cur];//be lazy and don't propogate to your children
}


void add(int start, int end, int cur = 1, int f=0, int b=MAX){//includes start but NOT END f and b are front and back of node
    
    if(f>=end||b<=start) return;
    if(f>=start&&b<=end){
        lazy(cur,f,b);
        return;
    }
    int mid = (b+f)/2;
    if(cur<MAX&&LAZY[cur]){
        lazy(2*cur,f,mid);
        lazy(2*cur+1,mid,b);
    }
    LAZY[cur] = false;
    add(start, end, 2*cur, f, mid);
    add(start, end, 2*cur+1, mid, b);
    //part of your seg tree is now changed
    SEG[cur] = SEG[2*cur]+SEG[2*cur+1];
}
int find(int start, int end, int cur = 1, int f = 0, int b = MAX){
    if(f>=end||b<=start) return 0;//if outside return 0
    if(f>=start&&b<=end) return SEG[cur];//if completely inside return yourself
    //now we must propogate to children before continuing
    int mid = (f+b)/2;
    if(cur<MAX&&LAZY[cur]){
        lazy(2*cur,f,mid);
        lazy(2*cur+1,mid,b);
    }
    LAZY[cur] = false;

    int ans = find(start,end,2*cur,f,mid)+find(start,end,2*cur+1,mid,b);
    SEG[cur] = SEG[2*cur]+SEG[2*cur+1];
    return ans;
}





int main(){
    freopen("lites.in", "r", stdin);
    freopen("lites.out", "w", stdout);
    int stalls, num;
    scanf("%d%d", &stalls, &num);
    int a, b, c;
    for(int x = 0;x<num;x++){
        scanf("%d%d%d", &a, &b, &c);
        if(a==0) add(b-1,c);
        else{
            int p = find(b-1,c);
            printf("%d\n", p);
        }
    }
    

}
