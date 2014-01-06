#include <cstdio>
#include <queue>
#include <utility>

#define A first
#define B second

using namespace std;
typedef pair<int,int> pii;

priority_queue<pii> q;

int N,M;
int cnt[110];
int run(int cow, int num, int total){//cow and num on field
    while(!q.empty()) q.pop();
    total-=cnt[0];
    for(int x = 1;x<M;x++){
        if(cnt[x]!=0) q.push(pii(cnt[x],x));
    }
    for(int x = 0;x<total;x++){
        pii cur = q.top();
        q.pop();
        cur.A--;
        if(num==0){
            cow = cur.B;
            num++;
        }
        else if(cow==cur.B) num++;
        else num--;
        if(cur.A!=0) q.push(cur);
    }
    if(cow==0) return num+cnt[0];
    else return cnt[0]-num;
}


int main(){
    freopen("gangs.in","r",stdin);
    freopen("gangs.out","w",stdout);
    scanf("%d%d",&N,&M);
    for(int x = 0;x<M;x++) scanf("%d",cnt+x);
    int solution = run(-1,0,N);
    if(solution>0) printf("YES\n%d\n",solution);
    else{
        printf("NO\n");
        return 0;
    }
    int control = -1;
    int num = 0;
    bool worked = false;
    for(int a = N-1;a>=0;a--){
        for(int x = 0;x<M;x++){
            worked =false;
            if(cnt[x]==0) continue;
            cnt[x]--;
            if(num==0){
                if(run(x,1,a)==solution){
                    control = x;
                    num = 1;
                    worked = true;
                }
            }
            else if(control==x){
                if(run(control,num+1,a)==solution){
                    worked = true;
                    num++;
                }
            }
            else if(run(control,num-1,a)==solution){
                worked = true;
                num--;
            }
            if(worked){
                printf("%d\n",x+1);
                break;
            }
            cnt[x]++;
            
        }
    }
    return 0;
}
