#include <cstdio>

using namespace std;

typedef long long ll;

int money[] = {1,2,5,10,20,50,100,200};
ll dp[220][10];

ll sack(int sum=200, int index=0){
    if(sum<0) return 0;
    if(sum==0) return 1;
    if(index>7) return 0;
    if(dp[sum][index]!=0) return dp[sum][index];
    return dp[sum][index] = sack(sum-money[index],index)+sack(sum,index+1);
    //if you use it, keep the option of using it
    //if you don't then proceed to the next knapsack index

}
int main(){
    printf("%lld",sack());
}


