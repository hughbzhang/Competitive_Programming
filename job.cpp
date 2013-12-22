#include <cstdio>
#include <algorithm>
#include <queue>
#define MAXN 100100
#define MAX 1000000100
#define START 1000000000
#define A first
#define B second

using namespace std;
typedef pair<int,int> pii;
typedef priority_queue<int, vector<int>, greater<int> > HEAP;

int jobs;
pii list[MAXN];
HEAP heap;
int main(){
    freopen("job.in","r",stdin);
    freopen("job.out","w",stdout);
    scanf("%d",&jobs);
    int a,b;
    for(int x = 0;x<jobs;x++){
        scanf("%d%d",&a,&b);
        list[x] = pii(a,b);//deadline then profit
    }
    sort(list,list+jobs);
    int cnt = 0;
    int num = 0;
    long long ans = 0;
    while(cnt<jobs){
        ans+=list[cnt].B;
        heap.push(list[cnt].B);
        num++;
        while(num>list[cnt].A){
            ans-=heap.top();
            heap.pop();
            num--;
        }
        
        cnt++;
    }
    printf("%lld\n",ans);
                


    return 0;
}
