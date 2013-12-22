//We use a SEG Tree solution
#include <cstdio>
#define MAX (1<<17)
#define END (1<<16)

using namespace std;
typedef long long ll;

struct node{
    ll YLYR;
    ll YLNR;
    ll NLYR;
    ll NLNR;
    //N = no
    //Y = yes
    //L = left
    //R = right
};

node SEG[MAX];
//l = 1, r = 2 refers to index #1

int num, days;

ll max(ll one, ll two){
    if(one>two) return one;
    else return two;
}

bool query(int index, int num, int l = 0, int r = END, int cur = 1){//DOES NOT INCLUDE END
    if(index>=r||index<l) return false;//out of bounds
    if(cur>=MAX) return false;
    if(l==r-1){
        SEG[cur].YLYR = num;
        SEG[cur].YLNR = 0;
        SEG[cur].NLYR = 0;
        SEG[cur].NLNR = 0;
        return true;
        //changed here
    }
    int m = l+(r-l)/2;
    if(query(index,num,l,m,2*cur)||query(index,num,m,r,2*cur+1)){//we must update ourselves
        node &left = SEG[2*cur];
        node &right = SEG[2*cur+1];
        SEG[cur].YLYR = max(left.YLNR+right.YLYR,left.YLYR+right.NLYR);
        SEG[cur].YLNR = max(left.YLYR+right.NLNR,left.YLNR+right.YLNR);
        SEG[cur].NLYR = max(left.NLYR+right.NLYR,left.NLNR+right.YLYR);
        SEG[cur].NLNR = max(left.NLYR+right.NLNR,left.NLNR+right.YLNR);
        return true;
    }
    //printf("problem\n");
    return true;
}

void print(){
    for(int x = 0;x<MAX;x++){
        printf("%lld ",SEG[x].YLYR);
    }
    printf("\n");
}

int main(){
    freopen("optmilk.in","r",stdin);
    freopen("optmilk.out","w",stdout);
    scanf("%d%d",&num,&days);
    int a,b;
    for(int x = 0;x<num;x++){
        scanf("%d",&a);
        query(x,a);
    }
    ll ans = 0; 
    for(int x = 0;x<days;x++){
        scanf("%d%d",&a,&b);
        query(a-1,b);
        ans += SEG[1].YLYR;
    }
    printf("%lld\n",ans);
    return 0;
}
