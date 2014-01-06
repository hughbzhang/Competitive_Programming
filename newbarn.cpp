#include <cstdio>
#include <utility>
#include <algorithm>
#include <set>
#define MAX 10100
#define A first
#define B second

using namespace std;
typedef pair<int,int> pii;

pii cows[MAX];
set<pii> tot;
int num;
int X[MAX];
int Y[MAX];

int m(int one, int two){
    if(one<=two) return one;
    else return two;
}


int cmp(pii a, pii b){
    return a.B<b.B;
}
int abs(int in){
    if(in<0) return -in;
    else return in;
}

int minx, miny, maxx,maxy;
long long cnt = 0;
long long dist = 0;
int main(){
    freopen("newbarn.in","r",stdin);
    freopen("newbarn.out","w",stdout);
    scanf("%d",&num);
    int a,b;
    for(int x = 0;x<num;x++){
        scanf("%d%d",&a,&b);
        cows[x] = pii(a,b);
        tot.insert(cows[x]);
        X[x] = a;
        Y[x] = b;
    }
    sort(X,X+num);
    sort(Y,Y+num);
    sort(cows,cows+num);
    if(num%2==0){
        minx = cows[num/2-1].A;
        maxx = cows[num/2].A;
    }
    else{
        minx = cows[num/2].A;
        maxx = minx;
    }
    sort(cows,cows+num,cmp);
    if(num%2==0){
        miny = cows[num/2-1].B;
        maxy = cows[num/2].B;
    }
    else{
        miny = cows[num/2].B;
        maxy = minx;
    }
    cnt = (maxy-miny+1)*(long long)(maxx-minx+1);
    for(int x = 0;x<num;x++){
        if(cows[x].A>=minx&&cows[x].A<=maxx&&cows[x].B>=miny&&cows[x].B<=maxy) cnt--;
    }
    /*for(int x = minx;x<=maxx;x++){
        for(int y = miny;y<=maxy;y++){
            if(tot.count(pii(x,y))==0) cnt++;
        }
    }*/
    for(int x = 0;x<num;x++){
            dist+=abs(cows[x].A-(long long)minx)+abs(cows[x].B-(long long)miny); 
    }
    
    if(cnt!=0){
        printf("%lld %lld\n",dist,cnt);
    }
    else{
        int dist1 = 0;
        int dist2 = 0;
        int dist3 = 0;
        int dist4 = 0;
        for(int x = 0;x<num;x++){
            dist1+=abs(cows[x].A-(long long)(minx+1))+abs(cows[x].B-(long long)miny); 
            dist2+=abs(cows[x].A-(long long)(minx-1))+abs(cows[x].B-(long long)miny); 
            dist3+=abs(cows[x].A-(long long)minx)+abs(cows[x].B-(long long)(miny+1)); 
            dist4+=abs(cows[x].A-(long long)minx)+abs(cows[x].B-(long long)(miny-1)); 
        }
        int min = m(m(dist1,dist2),m(dist3,dist4));
        if(dist1==min) cnt++;
        if(dist2==min) cnt++;
        if(dist3==min) cnt++;
        if(dist4==min) cnt++;
        printf("%d %lld\n",min,cnt);
    }
    return 0;

}
