#include <cstdio>
#include <utility>
#include <queue>
#define A first
#define B second
#define LARGE 10000
using namespace std;
typedef pair<int,int> pii;//y then x
typedef pair<int,pii> piii;//cost then position
int length,width;
int field[600][600];
int dist[600][600];
pii doc,cap;
pii null = pii(-1,-1);
//true is normal (go to length)
//false is flipped (go to 0)
// 0 is empty
// 1 is full
// 2 is Captain
// 3 is Doctor
void search(int y,int x,bool grav,int best);
void left(int y, int x,bool grav, int best);
void right(int y, int x, bool grav, int best);

void printDist(){
    for(int y = 0;y<length;y++){
        for(int x = 0;x<width;x++){
            if(dist[y][x]==LARGE) printf("#");
            else printf("%d",dist[y][x]);
        }
        printf("\n");
    }
}
void print(){
    for(int y = 0;y<length;y++){
        for(int x = 0;x<width;x++){
            printf("%d ",field[y][x]);
        }
        printf("\n");
    }
}

pii fall(int y,int x, bool grav,int best){
    if(field[y][x]==1) return null;
    if(!grav){
        while(true){
            if(field[y][x]==3){
                dist[y][x] = best;
                return null;
            }
            if(y<=0) return null;//fall into oblivion
            if(field[y-1][x]!=1) y--;//fall if not full
            else break;
        }
        return pii(y,x);
    }
    else{
        while(true){
            if(field[y][x]==3){
                dist[y][x] = best;
                return null;
            }
            if(y>=length-1) return null;
            if(field[y+1][x]!=1) y++;
            else break;  
        }
        return pii(y,x);
    }
}
void right(int y,int x,bool grav,int best){
    x++;
    if(best>=dist[y][x]) return;
    pii cur;
    while(x<length){
        cur = fall(y,x,grav,best);
        if(cur==null) return;
        y = cur.A;
        x = cur.B;
        if(best<dist[y][x]){
            dist[y][x] = best;
            if(field[y][x]==3) return;
            pii next = fall(y,x,!grav,best+1);
            if(next!=null) search(next.A,next.B,!grav,best+1);
            left(y,x,grav,best);
        }
        x++;
    }
}
void left(int y,int x,bool grav,int best){
    x--;
    if(best>=dist[y][x]) return;
    pii cur;
    while(x>=0){
        cur = fall(y,x,grav,best);
        if(cur==null) return;
        y = cur.A;
        x = cur.B;
        if(best<dist[y][x]){
            dist[y][x] = best;
            if(field[y][x]==3) return;
            pii next = fall(y,x,!grav,best+1);
            if(next!=null) search(next.A,next.B,!grav,best+1);
            right(y,x,grav,best);
        }
        x--;
    }
}


void search(int y,int x,bool grav,int best){
    if(x<0||x>=width||y<0||y>=length) return;
    if(field[y][x]==1) return;
    if(best>=dist[y][x]) return;
    dist[y][x] = best;
    if(field[y][x]==3) return;
    left(y,x,grav,best);
    right(y,x,grav,best);
    pii next = fall(y,x,!grav,best+1);
    if(next==null) return;
    search(next.A,next.B,!grav,best+1);
}


int main(){
    freopen("gravity.in","r",stdin);
    freopen("gravity.out","w",stdout);
    scanf("%d%d",&length,&width);
    char c;
    for(int y = 0;y<length;y++){
        for(int x = 0;x<width;x++){
            dist[y][x]=LARGE;
            scanf(" %c",&c);
            int &cur = field[y][x];
            if(c=='#') cur = 1;
            else if(c=='.') cur = 0;
            else if(c=='C') cur = 2;
            else if(c=='D') cur = 3;
            else printf("ERROR\n"); 
            if(c=='C') cap = pii(y,x);
            else if(c=='D') doc = pii(y,x); 
        }
    }
    pii start = fall(cap.A,cap.B,true,0);
    search(start.A,start.B,true,0);
    if(dist[doc.A][doc.B]==LARGE) printf("-1\n");
    else printf("%d\n",dist[doc.A][doc.B]);
    return 0;
}
