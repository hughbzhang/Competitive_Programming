#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
bool one = false;
bool two = false;
string arr[4];

int cmp(string one, string two){
    return one.length()<two.length();
}

int main(){
    for(int x = 0;x<4;x++) cin >> arr[x];
    sort(arr,arr+4,cmp);
    if(arr[0].length()*2-4<=arr[1].length()-2) one = true;
    if(arr[3].length()-2>=arr[2].length()*2-4) two = true;
    if(one&&!two) cout << arr[0].at(0) << endl;
    else if(two&&!one) cout << arr[3].at(0) << endl;
    else cout << "C\n";
    return 0;
}
