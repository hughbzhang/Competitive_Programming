/*
ID: bigfish2
TASK: job
LANG: C++
*/

#include <cstdio>
#include <queue>
#include <algorithm>
#include <utility>
#include <vector>

#define MAX 1000
#define A first
#define B second

using namespace std;
typedef pair<int,int> pii;

int num, numA, numB;

int A[MAX];
int B[MAX];
priority_queue<pii,vector<pii>,greater<pii> > q;

//finish time, then work time

int main(){
    freopen("job.in","r",stdin);
    freopen("job.out","w",stdout);
    scanf("%d%d%d",&num,&numA,&numB);
    int a;
    for(int x = 0;x<numA;x++){
        scanf("%d",&a);
        q.push(pii(a,a));
    }
    for(int x = 0;x<num;x++){
        pii cur = q.top();
        q.pop();
        A[x] = cur.A;
        cur.A+=cur.B;
        q.push(cur);
    }
    while(!q.empty()) q.pop();
    for(int x = 0;x<numB;x++){
        scanf("%d",&a);
        q.push(pii(a,a));
    }
    printf("%d ",A[num-1]);
    for(int x = 0;x<num;x++){
        pii cur = q.top();
        q.pop();
        B[x] = cur.A;
        cur.A+=cur.B;
        q.push(cur);
    }
    int max = 0;
    reverse(B,B+num);
    for(int x = 0;x<num;x++){
        if(A[x]+B[x]>max) max = A[x]+B[x];
    }
    printf("%d\n",max);

}
