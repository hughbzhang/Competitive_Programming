#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>

#define A first
#define B second

using namespace std;
typedef pair<int,int> pii;

priority_queue<pii> q;
int total,num;
pii boards[100100];
int cutoff[100100];

int main(){
    freopen("corral.in","r",stdin);
    scanf("%d%d",&total,&num);
    int a,b;
    for(int x = 0;x<num;x++){
        scanf("%d%d",&a,&b);
        boards[x] = pii(a,b);
    }
    sort(boards,boards+num);
    int start = 0;
    int cur = 0;
    int index = 0;
    int cnt = 0;
    int begin = 0;
    while(cur<start+num){
        while(boards[index].A<=cur){
            q.push(pii(boards[index].A+boards[index].B,index));
            ++index;
            if(index==num){
                break;
            }
        }
        cur = q.top().A;
        cutoff[cnt] = cur;
        ++cnt;
    }

    return 0;

}
