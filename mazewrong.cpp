#include <cstdio>
#include <map>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <utility>
#include <set>

#define A first
#define B second

using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;

int M,N,T;
int Sx,Sy,Ex,Ey;
char maze[150][150];
queue<piii> q;
set<pii> all[4];
int ans = -1;
string temp;
int vis[150][150];

void clear(){
    while(!q.empty()) q.pop();
    for(int x = 0;x<4;x++) all[x].clear();
    ans = -1;
    for(int y = 0;y<M;y++) for(int x = 0;x<N;x++) vis[y][x] = 0;
}


void search(int b,int a, int i, int index){
    switch((index+i)%4){
        case 0:
            for(int x = a+1;x<N;x++){
                if(maze[b][x]!='S'&&maze[b][x]!='G'&&maze[b][x]!='.'){
                    break;
                }
                all[index].insert(pii(x,b));
            }
            break;
         case 2:
            for(int x = a-1;x>=0;x--){
                if(maze[b][x]!='S'&&maze[b][x]!='G'&&maze[b][x]!='.'){
                    break;
                }
                all[index].insert(pii(x,b));
            }
            break;
         case 1:
            for(int y = b+1;y<M;y++){
                if(maze[y][a]!='S'&&maze[y][a]!='G'&&maze[y][a]!='.'){
                    break;
                }
                all[index].insert(pii(a,y));
            }
            break;
         case 3:

            for(int y = b-1;y>=0;y--){
                if(maze[y][a]!='S'&&maze[y][a]!='G'&&maze[y][a]!='.'){
                    break;
                }
                all[index].insert(pii(a,y));
            }
            break;
    }
}

int main(){
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin >> T;
    for(int t = 1;t<=T;t++){
        clear();
        cin >> M >> N;
        for(int y = 0;y<M;y++){
            cin >> temp;
            for(int x = 0;x<N;x++){
                maze[y][x] = temp.at(x);
                if(maze[y][x]=='S'){
                    Sx = x;
                    Sy = y;
                }
                if(maze[y][x]=='G'){
                    Ex = x;
                    Ey = y;
                }
            }
        }
        for(int y = 0;y<M;y++){
            for(int x = 0;x<N;x++){
                if(maze[y][x]=='v'||maze[y][x]=='^'||maze[y][x]=='>'||maze[y][x]=='<'){
                    int index = 0;
                    if(maze[y][x] == 'v') index = 1;
                    if(maze[y][x] == '<') index = 2;
                    if(maze[y][x] == '^') index = 3;
                    if(maze[y][x] == '>') index = 0;
                    for(int a = 0;a<4;a++) search(y,x,index, a);
                }
            }
        }
        q.push(piii(0,pii(Sx,Sy)));
        while(!q.empty()){
            piii now = q.front();
            q.pop();
            int D = now.A;
            int X = now.B.A;
            int Y = now.B.B;
            if(X<0||X>=N||Y<0||Y>=M) continue;
            if(vis[Y][X]>=2) continue;
            //if(vis[Y][X][D]) continue;
            if(D!=0&&all[D%4].count(pii(X,Y))!=0) continue;
            if(maze[Y][X] != '.' && maze[Y][X]!= 'S' && maze[Y][X]!= 'G') continue;
            if(X==Ex&&Y==Ey){
                ans = D;
                break;
            }
//if(t==14)            cout << X << " " << Y << " " << D << endl;
            vis[Y][X]++;
            q.push(piii(D+1,pii(X+1,Y)));
            q.push(piii(D+1,pii(X-1,Y)));
            q.push(piii(D+1,pii(X,Y+1)));
            q.push(piii(D+1,pii(X,Y-1)));
        }
        cout << "Case #" << t << ": ";
        if(ans==-1) cout << "impossible" << endl;
        else cout << ans << endl;
        //if(t==3)    for(int x = 0;x<4;x++) cout << all[x].size() << endl;
     //   for(set<pii>::iterator i = all[3].begin();i!=all[3].end();++i){
      //      cout << i->A << " " << i->B << endl;
       // }
      //  return 0;
    }
}


