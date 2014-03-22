#include <cstdio>
#include <iostream>

#define MAX 100010
#define LARGE (1e10)
#define MAXK 505

using namespace std;
typedef long long ll;

int num,paths,types;
int start[MAXK];

int dad[MAX];
int rev[MAX];
ll path[MAXK][MAXK];


int find(int in){
    if(dad[in]==in) return in;
    else return dad[in] = find(dad[in]);
}
bool same(int one,int two){
    find(one);
    find(two);
    return dad[one]==dad[two];
}

void merge(int one, int two){//only call if not same
    if(same(one,two)) return;
    find(one);
    find(two);
    dad[dad[one]] = dad[two];
}


int main(){

    cin >> num >> paths >> types;
    for(int x = 0;x<types;x++){
        for(int y = 0;y<types;y++){
            if(y==x) continue;
            path[y][x] = LARGE;
        }
    }
    for(int x = 1;x<=num;x++) dad[x] = x;
    start[0] = 1;
    int in;
    for(int x = 1;x<=types;x++){
        cin >> in;
        start[x] = start[x-1]+in;
    }
    int now = 1;
    for(int x = 1;x<=num;x++){
        if(x<start[now]) rev[x] = now-1;
        else{
            now++;
            rev[x] = now-1;
        }
    }

//    for(int x = 1;x<=num;x++) cout << rev[x] << endl;
    int a,b,c;
    for(int x = 0;x<paths;x++){
        cin >> a >> b >> c;
        if(c==0) merge(a,b);            
        if(c<path[rev[a]][rev[b]]) path[rev[a]][rev[b]] = c;
        if(c<path[rev[b]][rev[a]]) path[rev[b]][rev[a]] = c;
    } 
    for(int x = 0;x<types;x++){
        for(int a = start[x]+1;a<start[x+1];a++){
            if(!same(start[x],a)){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    for(int k = 0;k<types;k++){
        for(int a = 0;a<types;a++){
            for(int b = 0;b<types;b++){
                if(path[a][k]+path[k][b]<path[a][b]) path[a][b] = path[a][k]+path[k][b];
            }
        }
    }
    for(int y = 0;y<types;y++){
        for(int x = 0;x<types;x++){
            if(path[y][x]==LARGE) path[y][x] = -1;
            cout << path[y][x] << " ";
        }
        cout << endl;
    }



    return 0;
}
