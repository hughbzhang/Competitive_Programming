#include <cstdio>
#include <algorithm>
#include <cmath>

#define MAXN (1<<17)

using namespace std;

typedef long long ll;

int num,length,course;

int speed[MAXN];
int key[MAXN];
ll laps[MAXN];
ll BIT[MAXN];
ll suf[MAXN];
double sec;

//1 indexing FTW
ll sum(int a){
    ll ans = 0; 
    while(a>0){
        ans+=BIT[a];
        a-=(a&(-a));
    }
    return ans;
}
void add(int a,int sum){
    if(!a) return;
    while(a<MAXN){
        BIT[a]+=sum;
        a+=(a&(-a));
    }
}
ll slow(int a){
    ll sum = 0;
    for(int x = 1;x<=a;x++){
        sum+=laps[x];
    }
    return sum;
}

bool comp(int a,int b){
    if(suf[a]==suf[b]) return laps[a]>laps[b];
    return suf[a]>suf[b];
}


int main(){
    
    freopen("running.in","r",stdin);
    //freopen("running.out","w",stdout);
    scanf("%d%d%d",&num,&course,&length);
    for(int x = 1;x<=num;x++){
        scanf("%d",speed+x);
    }
    sort(speed+1,speed+num+1);
    //printf("speed %f\n",sec);
    for(int x = 1;x<=num;x++){
        key[x] = x;
        laps[x] = floor(((double)speed[x]*course)/speed[num]);
        suf[x] = speed[x]*course%speed[num];
        add(x,laps[x]);
    }
    //im just going from small to large
    sort(key+1,key+num+1,comp);
    long long ans = 0;
    for(int x = 1;x<=num;x++){
        ans+=(key[x]-1)*laps[key[x]];
        ans-=sum(key[x]-1);
        add(key[x],1);
    }
    printf("%lld\n",ans);
    return 0;
}
