#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;
string a;
string good;
string bad;
string top;
string bot;

int main(){
    freopen("in.txt","r",stdin);
    int N;
    cin >> N;
    for(int x = 0;x<N;x++){
        cin >> a;
        bot = a;
        good = a;
        bad = a;
        top = a;
        sort(bot.begin(),bot.end());
        sort(top.begin(),top.end());
        reverse(top.begin(),top.end());

//        cout << bot << " " << good << " " << bad << " " << top << endl;
        for(int b = 0;b<a.length();b++){
            if(b==0&&bot.at(0)=='0'){
                bad = bot;
                if(bad.length()==1) break;
                bad.at(0) = bad.at(1);
                bad.at(1) = '0';
                break;
            }
            if(bad.at(b)!=bot.at(b)){
                char temp = bad.at(b);
                bad.at(b) = bot.at(b);
                for(int c = b+1;c<a.length();c++){
                    if(bad.at(c)==bot.at(b)) bad.at(c) = temp;
                }
                break;
            }
        }
        for(int b = 0;b<a.length();b++){
            if(good.at(b)!=top.at(b)){
                char temp = good.at(b);
                good.at(b) = top.at(b); 
                for(int c = b+1;c<a.length();c++){
                    if(good.at(c)==top.at(b)) good.at(c) = temp;
                }
                break;
            }
        }
        cout << "Case #" << x+1 << ": ";
        cout << bad << " " << good << "\n";

   }
}
