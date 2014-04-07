#include <cstdio>
#include <map>
#include <iostream>
#include <utility>

using namespace std;
typedef pair<int,int> pii;

int num, By,Bx;
int maxy,miny,maxx,minx;
int ans = 0;

map<pii,int> F;

bool search(int y, int x, int dir){
    if(y>maxy||y<miny||x>maxx||x<minx) return false;
    if(F[pii(y,x)]==0) return search(y,x+1,dir);
    if(y==By&&x==Bx) return true;
    else{
        return search(y-1,x,dir);
    }
}

int main(){
    freopen("optics.in","r",stdin);
    freopen("optics.out","w",stdout);
    ios::sync_with_stdio(0);
    cin >> num >> Bx >> By;
    for(int x = 0;x<num;x++){
        int a,b;
        char c;
        cin >> a >> b >> c;
        miny = min(miny,a);
        maxy = max(maxy,a);
        minx = min(minx,b);
        maxx = max(maxx,b);
        if(c=='/') F[pii(a,b)] = 1;
        else F[pii(a,b)] = 2;
    }
    for(int y = miny;y<=maxy;y++){
        for(int x = minx;x<=maxx;x++){
            if(search(y,x,0)) ans++;
        }
    }
    cout << ans << endl;
}
