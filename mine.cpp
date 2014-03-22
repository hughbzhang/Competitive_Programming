#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

ll prime = (1e9)+7;

ll past[5];
ll now[5];

//0-2 is normal
//3 is bomb
//4 is 1 with that side filled in
string in;



int main(){
    cin >> in;
    if(in.at(0)=='?'){
        past[0] = 1;//empty
        past[1] = 1;// 1 with no fill
        past[2] = 0;
        past[3] = 1;//bomb
        past[4] = 0;
    }
    else if(in.at(0)=='*'){
        past[3] = 1;
    }
    else if(in.at(0)=='0'){
        past[0] = 1;
    }
    else if(in.at(0)=='1') past[1] = 1;
    for(int x = 1;x<in.length();x++){
        char c = in.at(x);
        for(int x = 0;x<5;x++) now[x] = 0;
        switch(c){
            case '?':
            case '0':
                now[0] = past[0]+past[4];
                if(c!='?') break;
            case '1':
                now[1] = past[0]+past[4];
                now[4] = past[3];
                if(c!='?') break;
            case '2':
                now[2] = past[3];
                if(c!='?') break;
            case '*':
                now[3] = past[1]+past[2]+past[3];
                if(c!='?') break;
        }
        for(int x = 0;x<5;x++) now[x]%=prime;
        swap(past,now);
//        for(int x = 0;x<5;x++) cout << past[x] << " ";
//        cout << endl;
    }
    cout << (past[0]+past[3]+past[4])%prime << endl; 
}
