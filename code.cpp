#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int code[] = {5,'r'-'a'+1,'i'-'a'+1,3,1};

int main(){
    string in = "riddlesxxx";
    for(int x = 0;x<10;x++){
        cout << (char)('a'+(in.at(x)-'a'+code[x%5])%26);
    }
    
}
