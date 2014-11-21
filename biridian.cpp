#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>
#include <iostream>
#include <string>
#define A first
#define B second

using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;

string in;

int num[1010][1010];
bool vis[1010][1010];

int R,C;
int Ex,Ey,Sx,Sy;
int ans = 0;
int dist[1010][1010];
queue<piii> q;


int main(){
    cin >> R >> C;
    for(int y = 0;y<R;y++) for(int x = 0;x<C;x++) dist[y][x] = 99999;
    for(int x = 0;x<R;x++){
        cin >> in;
        for(int a = 0;a<C;a++){
            if(in.at(a)=='E'){
                Ey = x;
                Ex = a;
            }
            else if(in.at(a)=='S'){
                Sy = x;
                Sx = a;
            }
            else if(in.at(a)=='T') vis[x][a] = true;
            else num[x][a] = in.at(a)-48;
        }
    }
    q.push(piii(pii(Ey,Ex),0));
    while(!q.empty()){
        piii cur = q.front();
        q.pop();
        if(cur.A.A<0||cur.A.A>=R||cur.A.B<0||cur.A.B>=C) continue;
        if(vis[cur.A.A][cur.A.B]) continue;
        vis[cur.A.A][cur.A.B] = true;
        dist[cur.A.A][cur.A.B] = cur.B;

        q.push(piii(pii(cur.A.A+1,cur.A.B),cur.B+1));
        q.push(piii(pii(cur.A.A-1,cur.A.B),cur.B+1));
        q.push(piii(pii(cur.A.A,cur.A.B+1),cur.B+1));
        q.push(piii(pii(cur.A.A,cur.A.B-1),cur.B+1));
    }

    for(int y = 0;y<R;y++){
        for(int x = 0;x<C;x++){
            if(dist[y][x]<=dist[Sy][Sx]) ans+=num[y][x];
            //cout << dist[y][x] << " ";
        }
//        cout << endl;
    }
    cout << ans << endl;
}
