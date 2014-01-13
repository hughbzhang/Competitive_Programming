#include <cstdio>
#include <algorithm>
#include <queue>
#include <set>
#include <utility>
#define A first
#define B second
#define BEGIN (*(work.begin()))
#define END (*(work.end()))
#define EMPTY (pii(0,0))

using namespace std;
typedef pair<int,int> pii;//donetime, then machine #
typedef priority_queue<pii,vector<pii>,greater<pii> > minq;
typedef priority_queue<pii> maxq;

set<pii> work;

int num,numA,numB;
int A[40];
int B[40];
int t = 0;
int done[1100];
int cnt = 0;
int left;
//greedy solution
//all available machines are used as seen fit
//if no jobs left a better machine can "steal" a job if it is deemed more time efficient.
//works for A, not sure about B

pii min(){
    if(work.empty()) return EMPTY;
    pii cur = *(work.begin());    
    work.erase(work.begin());
    return cur;
}
pii max(){
    if(work.empty()) return EMPTY;
    set<pii>::iterator it = work.end();
    --it;
    return *it;
}



int main(){

    freopen("job.in","r",stdin);
    scanf("%d%d%d",&num,&numA,&numB);
    left = num;
    int junk;
    for(int x = 0;x<numA;x++){scanf("%d",A+x);}
    for(int x = 0;x<numB;x++){scanf("%d",B+x);}
    sort(A,A+numA);
    sort(B,B+numB);
    for(int x = 0;x<numA;x++){
        if(left==0) break;
        left--;
        work.insert(pii(A[x]+t,x));//push the initial machines on
    }
    while(!work.empty()){
        pii next = min();
        t = next.A;
        int cur = next.B;
        done[cnt] = t;
        cnt++;
        if(left!=0){
            left--;
            work.insert(pii(t+A[cur],cur));
        }
        else{
            pii steal = max();
            if(t+A[cur]<steal.A){
                work.erase((--work.end()));
                work.insert(pii(t+A[cur],cur));
            }
        }
    }

    return 0;
}
