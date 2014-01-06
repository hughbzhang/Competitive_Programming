#include <cstdio>
#include <algorithm>
#include <queue>



using namespace std;
typedef long long ll;


int num;
ll sec[30000];
ll boards[30000];

priority_queue<int,vector<int>, greater<int> > q;

ll ans = 0;

int main(){
    freopen("plank.in","r",stdin);
    freopen("plank.out","w",stdout);
    scanf("%d",&num);

    for(int x = 0;x<num;x++){
        scanf("%lld",boards+x);
        q.push(boards[x]);
    }
    sort(boards,boards+num);
    while(q.size()>1){
        int first = q.top();
        q.pop();
        int second = q.top();
        q.pop();
        ans+=first+second;
        q.push(first+second);
    }
    printf("%lld\n",ans);

}
