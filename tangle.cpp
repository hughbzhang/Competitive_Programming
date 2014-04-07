#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

string in;
bool cur[100010];
bool arr[100010];
int e = 0;
bool back = true;

int main(){
    cin >> in;
    for(int x = 0;x<in.length();x++){
        if(in.at(x)=='-') cur[x] = false;
        else cur[x] = true;
    }
    arr[0] = cur[0];
    
    for(int x = 1;x<in.length();x++){
        if(e==-1){
            e = 0;
            arr[0] = cur[x];
            continue;
        }
        if(arr[e]==cur[x]) e--;
        else arr[++e] = cur[x];
    }
    if(e==-1) cout << "Yes\n";
    else cout << "No\n";



    return 0;
}
