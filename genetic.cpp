#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string master;
int ans = 0;

int main(){
    cin >> master;
    master+='L';
    char cur = master.at(0);
    int start = 0;
    for(int x = 1;x<master.size();x++){
        if(master.at(x)!=cur){
            if((x-start)%2==0) ans++;
            cur = master.at(x);
            start = x;
        }
    }
    cout << ans << endl;


    return 0;
}
