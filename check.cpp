#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    char in,two;

    while(true){
        cin >> in >> two;
        cout << (char)(in-two+'a');
    }

}
