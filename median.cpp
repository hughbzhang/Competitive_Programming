#include <cstdio>
#include <set>
#include <utility>
#include <map>
#define A first
#define B second
using namespace std;

typedef pair<int,int> pii;

multiset<pii> table;
multiset<pii>::iterator med;
int cnt = 1;
int num;

map<int,int> rep;

int main(){
    freopen("median.in","r",stdin);    
    scanf("%d",&num);
    int a;
    scanf("%d",&a);
    table.insert(pii(a,0));
    rep[a]++;
    med = table.begin();
    for(int x = 1;x<num;x++){
        scanf("%d",&a);
        table.insert(pii(a,rep[a]));
        rep[a]++;
        ++cnt;
        if(cnt%2==0&&x<(*med).A) med--;
        if(cnt%2==1&&x>(*med).A) med++;
        printf("%d\n",(*med).A);
    }


    return 0;
}
