#include <cstdio>
#include <utility>
#include <algorithm>

#define A first
#define B second
#define MAX 100100

using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;


int R,C,P;
int a,b,c,mid;


int head[MAX];

piii list[MAX];
pii must[MAX];

int par(int x){
    if(head[x]==x) return x;
    else return head[x] = par(head[x]);
}

void merge(int A,int B){
    A = par(A);
    B = par(B);
    if(A==B) return;
    head[A] = B;
}

void build(int large){
    for(int x = 0;x<MAX;x++) head[x] = x;
    for(int x = 0;x<C;x++){
        if(list[x].A>large) break;
        merge(list[x].B.A,list[x].B.B);
    }
}
bool check(){
    for(int x = 0;x<P;x++){
        if(par(must[x].A)!=par(must[x].B)) return false;
    }
    return true;
}

int main(){
    scanf("%d%d",&R,&C);
    for(int x = 0;x<C;x++){
        scanf("%d%d%d",&a,&b,&c);
        a--;
        b--;
        list[x] = piii(c,pii(a,b));
    }
    sort(list,list+C);
    scanf("%d",&P);
    for(int x = 0;x<P;x++){
        scanf("%d%d",&a,&b);
        a--;
        b--;
        must[x] = pii(a,b);
    }
    int start = 1;
    int last = 1000005;
    while(start<last){
        mid = start+ (last-start)/2;
        build(mid);
        if(check()) last = mid;
        else start = mid+1;
    }
    if(start>1000000) printf("MISSION IMPOSSIBLE\n");
    else printf("%d\n",start);
}
