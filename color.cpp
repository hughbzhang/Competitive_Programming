#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

#define MAXN 6500

using namespace std;
typedef long long ll;
char in[10];
int a,b;
ll field[MAXN][MAXN];
ll row[MAXN];
ll col[MAXN];
bool colvis[MAXN];
bool rowvis[MAXN];
vector<int> order;
long long ans = 0;
int cur;
int N,P;

void print(){
    for(int y = 0;y<N;y++){
        for(int x = 0;x<N;x++){
            cout << field[y][x] << " ";
        }
        cout << endl;
    }
}

int main(){
    scanf("%d%d",&N,&P);
    ll ROW = N;
    ll COL = N;
    for(int x = 0;x<P;x++){
        scanf("%s%d%d",in,&a,&b);
        if(in[0]=='R'){
            row[a-1] = b;
            order.push_back(a);
        }
        else{
            col[a-1] = b;
            order.push_back(-a);
        }
        
    }

    reverse(order.begin(),order.end());
    for(int x = 0;x<order.size();x++){
        cur = order[x];
        if(cur<0){
            cur = -cur;
            cur--;
            if(colvis[cur]) continue;
            colvis[cur] = true;
            ans+=(ROW*col[cur]);
            COL--;
        }
        else{
            cur--;
            if(rowvis[cur]) continue;
            for(int x = 0;x<N;x++) if(!field[cur][x]) field[cur][x] = row[cur];
            rowvis[cur] = true;
            ans+=(COL*row[cur]);
            ROW--;
        }
    }
    cout << ans << endl;
}
