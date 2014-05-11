#include <cstdio>
#include <cmath>
#include <iostream>
#include <utility>
#define LOG 17
#define A first
#define B second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

int num;
pii arr[100000];
int hull[100000];
int e = 2;
int par[100000][18];
int lvl[100000];

bool cross(pii one, pii two){
    if(one.A*two.B-one.B*two.A>=0) return false;
    else return true;
}

bool cross(int one, int two, int thr){
    pii first = pii(arr[two].A-arr[one].A,arr[two].B-arr[one].B);
    pii sec = pii(arr[thr].A-arr[one].A,arr[thr].B-arr[one].B);
    return cross(first,sec);
}
pii level(pii in){//make the two the same level

     int a = in.A;
     int b = in.B;
//     cout << "A " << a << " " << b << endl;
     if(lvl[b]==lvl[a]) return in;
     else if(lvl[b]>lvl[a]){
        b = par[b][(int)log2(lvl[b]-lvl[a])];
        return level(pii(a,b));
     }
     else{
        a = par[a][(int)log2(lvl[a]-lvl[b])];
        return level(pii(a,b));
     }
}

int query(int a, int b){
    pii next = level(pii(a,b));
    a = next.A;
    b = next.B;
    for(int y = 17;y>0;y--){
        if(par[a][y]!=par[b][y]){
            a = par[a][y];
            b = par[b][y];
            y++;
        }
    }
    while(a!=b){
        a = par[a][0];
        b = par[b][0];
    }
    
    return a;
}



int main(){
    //freopen("in.txt","r",stdin);
    cin >> num;
    ll a,b;
    for(int x = 0;x<num;x++){
        cin >> a >> b;
        arr[x] = pii(a,b);
    }
    for(int x = 0;x<18;x++){
        par[num-1][x] = num-1;
        par[num-2][x] = num-1;
    }
    lvl[num-1] = 0;
    lvl[num-2] = 1;
    hull[0] = num-1;
    hull[1] = num-2;
    for(int x = num-3;x>=0;x--){
        while(e>1&&cross(hull[e-2],hull[e-1],x)) e--;
        hull[e++] = x;
        par[x][0] = hull[e-2];
        for(int a = 1;a<18;a++){
            par[x][a] = par[par[x][a-1]][a-1]; 
        }
        lvl[x] = lvl[par[x][0]]+1;
    }
    int ha;
    cin >> ha;
    for(int x = 0;x<ha;x++){
        scanf("%d%d",&a,&b);
        cout << query(a-1,b-1)+1 << endl;
    }
//    cout << ans.A << " " << ans.B << endl;

}


