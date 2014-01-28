#include <cstdio>
#include <queue>
#include <utility>

#define A first
#define B second

using namespace std;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;

queue<piii> q;
int dist[8][8];
int cnt[8][8];

void init(){
    for(int y = 0;y<8;y++){
        for(int x = 0;x<8;x++){
            dist[y][x] = (1e5);
        }
    }
}

int main(){
    init();
    q.push(piii(0,pii(0,0)));
    while(!q.empty()){
        piii cur = q.front();
        q.pop();
        int cost = cur.A;
        int Y = cur.B.A;
        int X = cur.B.B;
        if(Y<0||Y>7||X<0||X>7) continue;
        if(cost>dist[Y][X]) continue;
        else if(cost==dist[Y][X]) cnt[Y][X]++;
        else{
            dist[Y][X] = cost;
            cnt[Y][X] = 1;
        }
        cost++;
        q.push(piii(cost,pii(Y+1,X+2)));
        q.push(piii(cost,pii(Y+1,X-2)));
        q.push(piii(cost,pii(Y-1,X+2)));
        q.push(piii(cost,pii(Y-1,X-2)));
        q.push(piii(cost,pii(Y+2,X+1)));
        q.push(piii(cost,pii(Y+2,X-1)));
        q.push(piii(cost,pii(Y-2,X+1)));
        q.push(piii(cost,pii(Y-2,X-1)));
    }
    for(int y = 0;y<8;y++){
        for(int x = 0;x<8;x++){
            printf("%d ",cnt[y][x]);
        }
        printf("\n");
    }

    return 0;
}
