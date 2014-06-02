#include <cstdio>
#include <iostream>

using namespace std;
long long num;
int check(long long b){
    long long now = num;
    int ans = 0;
    int pos = 0;
    while(now>0){
        if(now%b==4) pos++;
        else{
            if(pos>ans) ans = pos;
            pos = 0;
        }
        now/=b;
    }
    if(pos>ans) ans = pos;
    return ans;
}


int main(){
    freopen("four.in","r",stdin);
    freopen("four.out","w",stdout);
    ios::sync_with_stdio(0);
    while(cin >> num){
        int best = 0;
        long long base = 0;
        for(int x = 5;x<num;x++){
            int temp = check(x);
            if(temp>=best){
                 best = temp;
                 base = x;
            }
        }
        cout << best << " " << base << endl; 
    }

}
