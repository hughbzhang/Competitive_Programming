#include <cstdio>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>

#define A first
#define B second


using namespace std;
typedef pair<int,int> pii;//first the deadline then the amount

priority_queue<int,vector<int>,greater<int> > q;
pii list[10100];
int num;

int main(){
    freopen("msched.in","r",stdin);
    freopen("msched.out","w",stdout);
    scanf("%d",&num); 
    int a,b;
    for(int x = 0;x<num;x++){
        scanf("%d%d",&a,&b);
        list[x] = pii(b,a);
    }
    sort(list,list+num);
    for(int x = 0;x<num;x++){
        q.push(list[x].B);
        if(q.size()>list[x].A) q.pop();
    }
    long long ans = 0;
    while(!q.empty()){
        ans+=q.top();
        q.pop();
    }
    printf("%lld\n",ans);

    return 0;
}
