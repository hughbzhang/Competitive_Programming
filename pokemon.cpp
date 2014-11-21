#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

string arr[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int N;
string in;

int main(){
    cin >> N;
    cin >> in;
    for(int x = 0;x<8;x++){
        if(in.length()!=arr[x].length()) continue;
        bool flag = true;
        for(int a = 0;a<in.length();a++){
            if(in.at(a)!='.'&&in.at(a)!=arr[x].at(a)){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << arr[x] << endl;
            return 0;
        }
    }
}
