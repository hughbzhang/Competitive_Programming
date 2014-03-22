#include <cstdio>
#include <iostream>
#include <iomanip>
#define MAX 1001

using namespace std;
typedef long double ld;

ld dp[1011][1011][2];
//0 is princess
//white then black
int w,b;



int main(){
    cin >> w >> b;
    for(int y = 1;y<MAX;y++){
        //all other base cases dragon wins
        dp[y][0][0] = 1.0;

    }
    for(int y = 1;y<MAX;y++){
        for(int x = 1;x<MAX;x++){
            dp[y][x][0] = y/(ld)(y+x) + x*dp[y][x-1][1]/(x+y);
            
            dp[y][x][1] = y*dp[y-1][x-1][0]/(y+x-1);
            if(x>1) dp[y][x][1] += (x-1)*dp[y][x-2][0]/(y+x-1);
            dp[y][x][1] *= x/(ld)(y+x);
        }
    }
    
    cout << fixed << setprecision(12) << dp[w][b][0] << endl;

    return 0;
}
