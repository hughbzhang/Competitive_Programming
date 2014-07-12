#include <cstdio>
#include <vector>
#include <utility>
#include <iostream>
#include <cmath>
#define MAXN 60
#define A first
#define B second

using namespace std;
typedef long double ld;
typedef pair<ld,ld> pii;

const ld PI = 3.14159265358979;
bool vis[MAXN];
vector<pii> data;
int N,T,start,NEXT;
ld a,b,c;
ld NEXTA,past;

void clear(){
    N = 0;
    data.clear();
    start = 0;
    for(int x = 0;x<MAXN;x++) vis[x] = false;
    past = 0;
}

int main(){
    //freopen("in.txt","r",stdin);
    cin >> T;
    for(int t = 0;t<T;t++){
        clear();
        cin >> N;
        for(int x = 0;x<N;x++){
            cin >> a >> b >> c;
            data.push_back(pii(b,c));
            if(c<data[start].B) start = x;
        }
        cout << N << " ";
        for(int x = 0;x<N;x++){
            cout << start+1 << " ";
            vis[start] = true;
            NEXTA = 2*PI+past;
            NEXT = -1;
            for(int y = 0;y<N;y++){
                if(vis[y]) continue;
                ld angle = atan2(data[y].B-data[start].B,data[y].A-data[start].A);
                while(angle<past) angle += 2*PI;
                if(angle<NEXTA){
                    NEXTA = angle;
                    NEXT = y;
                }
            }
            past = NEXTA;
            start = NEXT;
        }
        cout << endl;
    }
}

