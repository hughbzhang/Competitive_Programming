#include <string>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <utility>
#define A first
#define B second

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
//first int is location
//second int is event
//0 is concrete wall
//1 is brick wall
//2 is fall
//
set<pii> s;

int tall,wide;
ll steps = 0;

int main(){
    //freopen("in.txt","r",stdin);
    cin >> tall >> wide;
    string now;
    string next;
    int loc = 0;
    bool dir = true;
    cin >> next;
    for(int x = 0;x<tall-1;x++){
        s.clear();
        s.insert(pii(-1,0));
        s.insert(pii(wide,0));
        now = next;
        cin >> next;
        for(int a = 0;a<now.size();a++){
            if(now.at(a)=='+') s.insert(pii(a,1));
            if(now.at(a)=='#') s.insert(pii(a,0));
            if(next.at(a)=='.'&&now.at(a)=='.') s.insert(pii(a,2));
        }
        bool fall = false;
        int hit = 0;
        while(!fall&&hit!=2){
            if(dir){
                pii lol = *(s.lower_bound(pii(loc,-1)));
                //cout << lol.A << " " << lol.B << endl;
                if(lol.B==2){
                    steps+=lol.A-loc+1;
                    loc = lol.A;
                    fall = true;
                    hit = 0;
                }
                else{
                    steps+=lol.A-loc;
                    loc = lol.A-1;
                    dir = !dir;
                    
                    if(lol.B==1){
                        hit = 0;
                        if(next.at(lol.A)=='.') s.insert(pii(lol.A,2));
                        s.erase(lol);
                    }
                    else hit++;
                }
            }
            else{
                pii lol = *(--(s.lower_bound(pii(loc,3))));
                //cout << lol.A << " " << lol.B << endl;
                if(lol.B==2){
                    steps+=loc-lol.A+1;
                    loc = lol.A;
                    fall = true;
                    hit = 0;
                }
                else{
                    steps+=loc-lol.A;
                    loc = lol.A+1;
                    dir = !dir;
                    if(lol.B==1){
                        if(next.at(lol.A)=='.') s.insert(pii(lol.A,2));
                        s.erase(lol);
                        hit = 0;
                    }
                    else hit++;
                }
            }

//        cout << "LOC " << loc << " " << dir << " " << steps<< endl;
        }
        if(hit==2){
            cout << "Never" << endl;
            return 0;
        }
    }
    cout << steps << endl;
}

