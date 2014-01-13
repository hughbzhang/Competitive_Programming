#include <cstdio>
#include <iostream>

using namespace std;
typedef long long ll;

int numA,numB,limitA,limitB;

long long dp[250][2][101][101];
ll mod = (1e8);

ll recurse(int cur, bool flag, int A, int B){
    if(A<0||B<0) return 0;
    if(flag&&cur>limitA) return 0;
    else if(!flag&&cur>limitB) return 0;
    if(dp[cur][flag][A][B]!=-1) return dp[cur][flag][A][B];
    if(A==0&&B==0) return 1;
    if(flag){
        dp[cur][flag][A][B]=recurse(cur+1,flag,A-1,B)+recurse(1,0,A,B-1);
        return (dp[cur][flag][A][B]%=mod);
    }
    else{
        dp[cur][flag][A][B]=recurse(cur+1,flag,A,B-1)+recurse(1,1,A-1,B);
        return dp[cur][flag][A][B]%=mod;
    }
}

int main(){
    cin >> numA >> numB >> limitA >> limitB;
    for(int y = 0;y<250;y++){
        for(int x = 0;x<101;x++){
            for(int a = 0;a<101;a++){
                dp[y][0][x][a] = -1;
                dp[y][1][x][a] = -1;
            }
        }
    }
    cout << recurse(0,0,numA,numB) << "\n";


}
