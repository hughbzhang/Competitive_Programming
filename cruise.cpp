#include <cstdio>
#include <iostream>
#include <string>
#define MAXN 1100
#define MAXM 500
#define MAXK 1000100000

using namespace std;

int port,dir,rep;
string str;
string junk;
int tree[MAXN][2];
int vis[MAXN];//the turn that it was visited
int end[MAXN];

int main(){

    freopen("cruise.in","r",stdin);
    freopen("cruise.out","w",stdout);
    scanf("%d%d%d",&port,&dir,&rep);
    for(int x = 1;x<=port;x++){
        scanf("%d%d",&tree[x][0],&tree[x][1]);
    }
    for(int x = 0;x<dir;x++){
        cin >> junk;
        str+=junk;
    }
    int cur = 1;
    for(int x = 1;x<=port;x++){
        cur = x;
        for(int y = 0;y<dir;y++){
            if(str.at(y)=='L') cur = tree[cur][0];
            else cur = tree[cur][1];   
        }
        end[x] = cur;
    }
    cur = 1;
    int stop = -1;
    for(int x = 0;x<MAXN;x++) vis[x] = -1;
    vis[1] = 0;//visit port 1 at turn 0
    for(int x = 1;x<=rep;x++){
        cur = end[cur];
        if(vis[cur]==-1) vis[cur] = x;
        else{
            stop = (rep-x)%(x-vis[cur]);
            break;
        }
    }
    for(int x = 0;x<stop;x++){
        cur = end[cur];
    }
    printf("%d\n",cur);

    return 0;

}
