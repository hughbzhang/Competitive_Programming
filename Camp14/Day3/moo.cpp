#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int two[10];

int main(){
    freopen("moo.in","r",stdin);
    freopen("moo.out","w",stdout);
    string now;
    string temp;
    two[6] = 1;
    for(int x = 1;x<7;x++){
        two[6-x] = 2*two[7-x]; 
    }
    while(getline(cin,now)){
        for(int x = 0;x<now.length();x++){
            if(now.at(x)!='M'&&now.at(x)!='o'&&now.at(x)!='O') cout << now.at(x);
            int next = two[0];
            if(now.at(x)=='M'){
                for(int a = x+1;a<x+7;a++){
                    bool lol = now.at(a)=='O';
                    next+=two[a-x]*lol;
                }
                cout << (char)next;
            }
        }
        cout << endl;
    }
}
