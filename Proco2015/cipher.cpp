#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string arr[30];

int main(){
    freopen("cipher.txt","r",stdin);
    for(int x = 0;x<20;x++){
        cin >> arr[x];
    }
    for(int x = 0;x<26;x++){
        for(int a = 0;a<20;a++){
            for(int b = 0;b<arr[a].length();b++){
                cout << (char)(((arr[a][b]-'a'+x)%26)+'a');
            }
            cout << endl << endl;
        }
    }
}
