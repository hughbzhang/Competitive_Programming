#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#define MAX (1<<20)
#define A first
#define B second

using namespace std;
typedef int ll;
typedef pair<int,int> pii;
typedef vector<pii>::iterator vi;

ll dp[MAX];//1 means you used it 0 means you haven't
//represents how much ive made so far
int length[MAX];//counts how many you have used so far
int skill[25][25];
int num,bonuses;
vector<pii> bonus[25];

ll recurse(int in){
    //printf("%d\n",in); 
    if(in==0) return 0;//if nothing left
    if(dp[in]!=-1) return dp[in];
    int l = length[in];
    for(int a = 0;a<num;a++){
        if((1<<a)&in){
            ll pos = recurse(in-(1<<a))+skill[a][l-1];
            if(pos>dp[in]) dp[in] = pos;
        }
    }
    for(vi it = bonus[l].begin();it!=bonus[l].end();++it){
        if(dp[in]>=(*it).A) dp[in]+=(*it).B;
        else break;
    }
    return dp[in];
}

int main(){
    freopen("dec.in","r",stdin);
    freopen("dec.out","w",stdout);
    scanf("%d%d",&num,&bonuses);
    for(int x = 0;x<bonuses;x++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        bonus[a].push_back(pii(b,c));
    }
    for(int x = 0;x<25;x++) sort(bonus[x].begin(),bonus[x].end());
    for(int y = 0;y<num;y++){
        for(int x = 0;x<num;x++){
            scanf("%d",&skill[y][x]);
        }
    }
    for(int x = 0;x<MAX;x++){
        dp[x] = -1;
        for(int a = 0;a<num;a++){
            if((1<<a)&x) length[x]++;
        }
    }
    printf("%d\n",recurse((1<<num)-1));
}
