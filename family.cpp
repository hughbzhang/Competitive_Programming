#include <cstdio>
#include <utility>
#include <algorithm>
#include <iostream>
#define A first
#define B second

using namespace std;
typedef pair<int,int> pii;
pii ori[3];
int X,Y,a,b;
pii ans[3];

int main(){
    for(int x = 0;x<3;x++){
        cin >> a >> b;
        ori[x] = pii(a,b);
    }
    for(int x = 0;x<3;x++){
        X = 0;
        Y = 0;
        for(int a = 0;a<3;a++){
            if(a==x){
                X-=ori[a].A;
                Y-=ori[a].B;
            }
            else{
                X+=ori[a].A;
                Y+=ori[a].B;
            }
        }
        ans[x] = pii(X,Y);
    }

    sort(ans,ans+3);
    for(int x = 0;x<3;x++){
        cout << ans[x].A << " " << ans[x].B << endl;
    }
}
