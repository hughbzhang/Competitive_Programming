#include <cstdio>
#define MAX (1<<17)
using namespace std;

int num;
int cnt = 0;
long long time;

int reverse[MAX];
bool lights[16];
int vis[MAX];
bool toggle[16];//whether to toggle or not

int convert(){
    int total = 0;
    int now = 1;
    for(int x = 0;x<num;x++){
        total+=now*lights[x];
        now*=2;
    }
    return total;
}

void print(){
    for(int x = 0;x<num;x++){
        printf("%d",lights[x]);
    }
    printf("\n");
}
void run(){
    if(lights[num-1]) toggle[0] = 1;
    else toggle[0] = 0;
    for(int x = 1;x<num;x++){
        if(lights[x-1]) toggle[x] = 1;
        else toggle[x] = 0;
    }
    for(int x = 0;x<num;x++){
        if(toggle[x]) lights[x] = !lights[x];
    }
    print();
}

int main(){
    freopen("blink.in","r",stdin);
    scanf("%d%lld",&num,&time);
    for(int x = 0;x<num;x++){
        int a;
        scanf("%d",&a);
        if(a==0) lights[x] = 0;
        else lights[x] = 1;
    }
    int now;
    
    while(true){
        now = convert();
        if(vis[now]) break;
        vis[now] = cnt;
        reverse[cnt] = now;
        run();
        cnt++;
    }
    int done = reverse[vis[now]+((time-vis[now])%(cnt-vis[now]))];
    for(int x = 0;x<num;x++){
        if(done&(1<<x)) printf("1\n");
        else printf("0\n");
    }

    return 0;
}
