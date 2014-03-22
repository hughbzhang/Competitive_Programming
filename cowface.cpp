#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int num;
int lefty[200100];//facing lefty
int righty[200100];//cows facing righty
int leftys = 0, rightys = 0;
int numlefty = 0,numrighty = 0;
long long ans = 0;
int main(){
    cin >> num;
    int temp;
    for(int x = 0;x<num;x++){
        cin >> temp;
        if(temp==0){
            lefty[numlefty] = x;
            numlefty++;
        }
        else{
            righty[numrighty] = x;
            numrighty++;
        }
    }
    int cur = 0;
    for(int x = 0;x<numrighty;x++){
        while(cur<numlefty&&lefty[cur]<righty[x]) cur++;
        ans+=(numlefty-cur);
    }
    cout << ans << endl;
}
