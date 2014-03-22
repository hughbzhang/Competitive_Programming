#include <cstdio>
#include <iostream>
#include <iomanip>

#define MAX 2050

using namespace std;
typedef long double ld;

int num,start;

ld dp[MAX][MAX];
//rows left
//cols left

bool R[MAX];
bool C[MAX];

int row, col;
ld total;

int main(){
    cin >> num >> start;
    int a,b;
    total = num*num;
    row = num;
    col = num;
    for(int x = 0;x<start;x++){
        cin >> a >> b;
        R[a] = true;
        C[b] = true;
    }
    for(int x = 1;x<=num;x++){
        if(R[x]) row--;
        if(C[x]) col--;
    }
    for(int x = 1;x<=num;x++){
        dp[x][0] = (dp[x-1][0]*x+num)/(ld)x;
        dp[0][x] = dp[x][0];
    }
    for(int y = 1;y<=row;y++){
        for(int x = 1;x<=col;x++){
            dp[y][x] = (num*num-num*y-num*x+x*y+(num-x)*y*(dp[y-1][x]+1)+(num-y)*x*(dp[y][x-1]+1)+x*y*(dp[y-1][x-1]+1))/(ld)(x*num+y*num-x*y);
        }
    }
    cout << fixed << setprecision(8);
    cout << dp[row][col] << endl;
    /*for(int y = 0;y<=num;y++){
        for(int x = 0;x<=num;x++){
            cout << dp[y][x] << " ";
        }
        cout << endl;
    }*/

    return 0;
}
