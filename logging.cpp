#include <cstdio>
#include <iostream>
#include <utility>

#define LARGE 1e10
#define MAX 1000000
#define A first
#define B second

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

int num;

ll height[MAX];
ll cost[MAX];
ll dp[MAX];
int q[MAX];
int front = 0, back = 1;

//returns true if you need to pop

bool inter(int a, int b, int c){//a is current line, b is last, c is second to last
    return((ld)dp[a]-dp[b])*((ld)cost[c]-cost[b])<=((ld)dp[b]-dp[c])*((ld)cost[b]-cost[a]);
}
bool rem(int a, int b,int cur){
    return (ld)dp[b]-dp[a]<=(ld)cur*(cost[a]-cost[b]); 
}



int main(){
    ios_base::sync_with_stdio(0);
    cin >> num;
    for(int x = 0;x<num;x++) cin >> height[x];
    for(int x = 0;x<num;x++) cin >> cost[x];
    for(int x = 0;x<num;x++) dp[x] = LARGE;
    dp[0] = 0; 
    q[0] = 0;
    for(int x = 1;x<num;x++){
        while(front<back-1&&rem(q[front],q[front+1],height[x])) front++;
        dp[x] = cost[q[front]]*height[x]+dp[q[front]];
        while(front<=back-2&&inter(x,q[back-1],q[back-2])) back--;             
        q[back] = x;
        back++;
        
    }
    for(int x = 0;x<num;x++){
        //cout << dp[x] << "\n";
    }
    cout << dp[num-1]<<"\n";
}
