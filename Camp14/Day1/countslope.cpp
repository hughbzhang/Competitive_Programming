#include <cstdio>
#include <iostream>
#include <utility>
#include <algorithm>
#define A first
#define B second
#define MAX 1000
using namespace std;
typedef pair<int,int> pii;
typedef long double ld;
pii points [MAX];
int num;
int now[MAX];
ld CURX;
int BIT[MAX];
int change[MAX];
int inv[MAX];

void add(int x){
    while(x<MAX){
        BIT[x]++;
        x+=(x&-x);
    }
}
int sum(int x){
    int ans = 0;
    while(x>0){
        ans+=BIT[x];
        x-=(x&-x);
    }
    return ans;
}
void clear(){
    for(int x = 0;x<MAX;x++) BIT[x] = 0;
}

int Y(int marker,int X){
    return points[marker].A*X+points[marker].B;
}

int comp(int a,int b){
    if(Y(a,CURX)<Y(b,CURX)) return 1;
    else return -1;
}

void search(int k){
    
    ld bot = -100000;
    ld top = 100000;
    while(bot<top-.01){
        CURX = (bot+top)/2;
        sort(now,now+num);
        for(int x = 0;x<num;x++){
            inv[now[x]] = x;
        }
        clear();
        int before = 0;
        for(int x = 0;x<num;x++){
            before+=inv[x]-sum(inv[x]);
            add(inv[x]);
        }
        if(k==before) return;
        else if(k<before) top = CURX;
        else bot = CURX;
    }
}

int main(){
    freopen("in.txt","r",stdin);
    scanf("%d",&num);
    for(int x = 0;x<num;x++){
        int a;
        int b;
        scanf("%d%d",&a,&b);
        points[x] = pii(a,b);
        now[x] = x;
    }
    sort(points,points+num);
    search(0);
    cout << CURX << endl;
    return 0;
}
