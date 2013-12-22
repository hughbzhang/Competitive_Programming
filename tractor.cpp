#include <cstdio>
#define MAXN 50500
#define MAX 1100
#define LARGE 10000000

using namespace std;

int TY,TX,num;//tractorX tractorY number of bales
int field[MAX][MAX];
bool hay[MAX][MAX];

void print(){
    for(int y = 0;y<MAX;y++){
        for(int x = 0;x<MAX;x++){
            printf("%d ",field[y][x]);
        }
        printf("\n");
    }
}

void init(){
    for(int y = 0;y<MAX;y++){
        for(int x = 0;x<MAX;x++){
            field[y][x] = LARGE;
        }
    }
}
void DFS(int y, int x,int dist){
    if(y<0||y>=MAX||x<0||x>=MAX) return;
    if(dist>=field[y][x]) return;//if youve already been here earlier go back
    field[y][x] = dist;//mark your spot
    DFS(y,x+1,dist+hay[y][x+1]);
    DFS(y,x-1,dist+hay[y][x-1]);
    DFS(y-1,x,dist+hay[y-1][x]);
    DFS(y+1,x,dist+hay[y+1][x]);
    return;
}


int main(){
    init();
    freopen("tractor.out","w",stdout);
    scanf("%d%d%d",&num,&TX,&TY);
    int a,b;
    for(int x = 0;x<num;x++){
        scanf("%d%d",&a,&b);
        hay[b][a] = true;
    }
    DFS(TY,TX,0);
    printf("%d\n",field[0][0]);
    return 0;
}
