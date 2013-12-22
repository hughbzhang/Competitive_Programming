#include <cstdio>
#include <queue>



using namespace std;

struct state{
    int y;
    int x;
    bool grav;//true is normal fall down to n

    //false is upside down and fall towards 0
    int dist;
};

queue<state> q;

int rows,cols;
int vis[510][510];
bool field[510][510];
int capY,capX;
int docY,docX;

void print(){
    for(int y = 0;y<rows;y++){
        for(int x = 0;x<cols;x++){
            printf("%d",vis[y][x]);
        }
        printf("\n");
    }
}

void end(state in){//are we done?
    if(in.x==docX&&in.y==docY){
        printf("%d\n",in.dist-1);
        exit(0);
    }
}

state fall(state in){
    state cur = {in.y,in.x,in.grav,in.dist};
    end(cur);
    if(!field[cur.y][cur.x]){
        cur.y = -1;
        return cur;
    }
    if(cur.grav){
        while(cur.y<rows-1){
            if(field[cur.y+1][cur.x])cur.y++;
            else break;
            end(cur);
        }
        if(cur.y>=rows-1) cur.y = -1;
    }
    else{
        while(cur.y>0){
            if(field[cur.y-1][cur.x])cur.y--;
            else break;
            end(cur);
        }
        if(cur.y<=0) cur.y = -1;
    }
    return cur;
}
void fill(state cur){
    if(!field[cur.y][cur.x]) return;
    if(cur.y==-1||cur.x==-1||cur.y>=rows||cur.x>=cols) return;
    if(vis[cur.y][cur.x]!=0) return;
    vis[cur.y][cur.x] = cur.dist;
    end(cur);
    state next = {cur.y,cur.x,!cur.grav,cur.dist+1};
    q.push(fall(next));
    cur.x++;
    fill(fall(cur));
    cur.x-=2;
    fill(fall(cur));
}


int main(){
    freopen("gravity.in","r",stdin);
    freopen("gravity.out","w",stdout);
    scanf("%d%d",&rows,&cols);
    char c;
    for(int y = 0;y<rows;y++){
        for(int x = 0;x<cols;x++){
            scanf(" %c",&c);
            if(c=='#')field[y][x]=false;//can't go here
            else field[y][x] = true;//you can go here
            if(c=='D'){
                docY = y;
                docX = x;
            }
            else if(c=='C'){
                capY = y;
                capX = x;
            }
        }
    }
    state start = {capY,capX,true,1};
    q.push(fall(start));
    while(!q.empty()){
        state cur = q.front();

//        printf("%d %d %d %d\n",cur.y,cur.x,cur.grav,cur.dist);
        fill(cur);
        q.pop();
    }
    printf("-1\n");
    


    return 0;
}
