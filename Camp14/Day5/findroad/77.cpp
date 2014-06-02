#include <cmath>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;
typedef long long ll;
typedef long double ld;
int R,C;
char in;
int pic[200][800][3];
bool ans[200][800];

long double gray[3];
long long num = 0;

int thresh = 250;
int bot = 80;
int top = 190;

ostringstream oss;
int main(){
    ios::sync_with_stdio(0);
    freopen("findroad.in","r",stdin);
    freopen("findroad.out","w",stdout);
    cin >> R >> C;
    for(int y = 0;y<R;y++){
        string ans = "";
        for(int x = 0;x<C;x++){
            ld average = 0;
            ld diff = 0;
            for(int a = 0;a<3;a++){
                cin >> pic[y][x][a]; 
                average+=pic[y][x][a];
            }
            average/=3;
            for(int a = 0;a<3;a++){
                diff+=(pic[y][x][a]-average)*(pic[y][x][a]-average); 
            }
            if(diff<thresh&&average>bot&average<top) ans+='y';
            else ans+='n';
            cin >> in;            
        }
        cout << ans << "\n";
    }
}
