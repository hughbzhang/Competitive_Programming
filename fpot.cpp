#include <cstdio>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#define A first
#define B second

using namespace std;
typedef pair <int,int> pii;

int comp(pii one, pii two){
    return one.B<two.B;
}


int num, t;
pii arr[100100];
multiset<pii> fast;

pii r(pii one){
    return pii(one.B,one.A);
}

int main(){
    freopen("in.txt","r",stdin);
    scanf("%d%d",&num,&t);
    int a,b;
    for(int x = 0;x<num;x++){
        scanf("%d%d",&a,&b);
        arr[x] = pii(a,b);
    }
    sort(arr,arr+num);
    int x = 1;
    int y = 0;
    fast.insert(r(arr[0]));
    fast.insert(r(arr[1]));
    pii top, bot;
    int best = 10000000;
    while(x<num){
        top = *(fast.begin());
        bot = *((fast.rbegin()));
        while(top.B<y){
            fast.erase(fast.begin());
            top = *(fast.begin());
        }
        while(bot.B<y){
            fast.erase(fast.find(bot));
            bot = *((fast.rbegin()));
        }
        if(abs(top.A-bot.A)>=t){
            if(best>abs(top.B-bot.B)) best = abs(top.B-bot.B);
            y = min(top.B,bot.B)+1;
        }
        else{
            x++;
            fast.insert(r(arr[x]));
        }
    }
    if(best==10000000) printf("-1\n");
    else printf("%d\n",best);
    
    return 0;
}
