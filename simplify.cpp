#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#define MAXN 40040
#define MAXM 100100
#define LARGE 1001000
#define A first
#define B second
using namespace std;

typedef pair<int, int> pii;//start+dest
typedef pair<int, pii > piii;//dist

int same[6];
int par[MAXN];//parent pointers
int MST[MAXN];
int num[LARGE];//number of each edge possible to be used
int used[LARGE];//number of each edge used
int inc = 0;
piii list[MAXM];
int pos[MAXM];
int incp = 0;
long long answer = 1;
long long sum = 0;
set<int> cyc;

int find(int a){
    if(par[a] == a) return a;//if at the root
    return par[a] = find(par[a]);
}

void add(int a, int b){
    a = find(a);
    b = find(b);
    par[a] = b;
}

bool check(int a, int b, int c, int d){
    if(a==c&&b==d) return true;
    else if(a==d&&b==c) return true;
    return false;
}
bool cycle(){
    cyc.clear();
    for(int x = 0;x<6;x++){
        cyc.insert(same[x]);
    }
    if(cyc.size()==3) return true;
    else return false;
}
void three(){
   bool one,two,thr; 
   one = check(same[0],same[1], same[2], same[3]);
   two = check(same[0],same[1], same[4], same[5]);
   thr = check(same[2],same[3], same[4], same[5]);
   if(one&&two&&thr)answer*=3;//all the same
   else if(one||two||thr) answer*=2;//two are the same
   else if(cycle()) answer*=3;//if there is a cycle, take 2 out of three
   //else do nothing
}


int main(){
    for(int x = 0;x<MAXN;x++) par[x] = x;
    freopen("simplify.in", "r", stdin);
    freopen("simplify.out", "w", stdout);
    int vert, edges;
    scanf("%d%d", &vert, &edges);
    int a, b, c;
    for(int x = 0;x<edges;x++){
        scanf("%d%d%d",&a,&b,&c);
        list[x] = piii(c,pii(a,b));
    }
    sort(list,list+edges);

    for(int x = 0;x<edges;x++){
        answer%=1000000007;       
        int temp = 0;
        int bonus = 0;
        piii old = list[x];
        while(list[x+bonus].A==old.A){//first go through and see how many could have been used
            piii cur = list[x+bonus];
            same[2*temp]=find(cur.B.A);
            same[2*temp+1]=find(cur.B.B);
            if(same[2*temp]!=same[2*temp+1]) temp++;
            bonus++;
        }
        if(temp==2&&check(same[0],same[1],same[2],same[3])) answer*=2; 
        else if(temp==3) three();

        for(int y = 0;y<bonus;y++){
            
            piii cur = list[y+x];
            if(find(cur.B.A)!=find(cur.B.B)){//if they are in different sets merge them
                MST[inc] = y;
                inc++;//add the edge to the MST
                add(find(cur.B.A),find(cur.B.B));
                sum+=cur.A;
                used[cur.A]++;
            }    
        }
        x += (bonus-1);    
    }
    printf("%lld %lld\n", sum,answer);        


    return 0;
}
