#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;

ll num;
ll best;
ll base;
ll top,bot;
bool flag;
const ll mil = 1000000;

int cnt(ll b){
    ll now = num;
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
ll eval(ll in, ll X = 4){
    return X*in*in+4*in+4;
}

int main(){
    freopen("four.in","r",stdin);
    freopen("four.out","w",stdout);
    while(cin >> num){    
        best = 0;
        for(int x = 5;x<=mil;x++){
            ll temp = cnt(x);
            if(temp>=best){
                 best = temp;
                 base = x;
            }
        }
        bot = 0;
        top = floor(sqrt(num));
        flag = false;
        while(bot<=top){
            ll mid = (top+bot)/2;
            if(eval(mid)==num){
                if(mid<5) break;
                bot = mid;
                top = mid;
                flag = true;
                break;
            }
            if(eval(mid)<num) bot = mid+1;
            else top = mid-1;
        }
        if(flag){
            if(best<3){
                base = bot;
                best = 3;
            }
            if(best==3) base = max(bot,base);
        }
        bot = 0;
        top = floor(sqrt(num));
        flag = false;
        if(best<=2){
            while(bot<=top){
               
                ll mid = (top+bot)/2;
                //if(mid==184516842) cout << "KLOL" << endl;
                if(num-eval(mid)+4<mid&&num-eval(mid)+4>=0){
                    if(mid<5) break;
                    bot = mid;
                    top = mid;
                    flag = true;
                    break;
                }
                if(num-eval(mid)+4>=mid) bot = mid+1;
                else top = mid-1;
            }
        }
        if(flag){
            if(best<2){
                best = 2;
                base = bot;
            }
            if(best==2) base = max(base,bot);
        }
//        cout << best << " " << base << endl;
        if(best<=2){
            ll past = num;
            for(int x = 0;x<mil;x++){
                bot = 0;
                top = past;
                flag = false;          
                while(bot<=top){
                    ll mid = (top+bot)/2;
                    if(eval(mid,x)==num){
                        if(x>=mid||mid<5) break;
                        bot = mid;
                        top = mid;
                        flag = true;
                        break;
                    }
                    if(eval(mid,x)<num) bot = mid+1;
                    else top = mid-1;
                }
                if(flag){
                    if(best<2){
                        best = 2;
                        base = bot;
                    }
                    if(best==2){
                         base = max(bot,base);
                    }
                }
                past = top;
            }
        }
        if(best<=1){
            best = 1;
            base = num-4;
        }
        printf("%lld %lld\n",best,base);
        fflush(stdout);
    }
}
