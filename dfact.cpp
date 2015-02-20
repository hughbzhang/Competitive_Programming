#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int N;
string in;
string out = "";

int main(){
    cin >> N >> in;
    for(int x = 0;x<N;x++){
        if(in.at(x)=='2'||in.at(x)=='3'||in.at(x)=='5'||in.at(x)=='7') out+=in.at(x);
        else if(in.at(x)=='4') out+="223";
        else if(in.at(x)=='6') out+="53";
        else if(in.at(x)=='8') out+="7222";
        else if(in.at(x)=='9') out+="7332";
    }
    sort(out.begin(),out.end());
    reverse(out.begin(),out.end());
    cout << out << endl;
}
